/*
 * ByteCodeReader.cpp
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#include <format/ReadInstruction.h>
#include <format/RegisterInstruction.h>
#include <format/OpCodeInstruction.h>
#include <format/PrimedRegister.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#define FILE_FORMAT_OPCODE_TYPE 	0
#define FILE_FORMAT_REGISTER_TYPE 	1
#define FILE_FORMAT_CONST_TYPE 		2

#define FILE_FORMAT_CONST_INT		0
#define FILE_FORMAT_CONST_FLOAT		1

class RegisterPrimer {
public:
	unsigned int added;
	PrimedRegister * op;

	RegisterPrimer() {
		op = NULL;
		added = 0;
	};

	bool isDone() {
		return op != NULL && op->registers() == added;
	};

	void addOp(int code) {
		op = new PrimedRegister(code);
		added = 0;
	};

	void addRegister(ByteCode & contents) {
		op->add(contents);
		added++;
	};
};

template<typename T>
T get_type(std::istream & is) {
	T result = 0;
	is.read(reinterpret_cast<char *>(&result), sizeof(T));
	return result;
}

std::istream & operator >>(std::istream & is, ByteCode & code) {
	OpCodeContents   * c1 = new OpCodeContents();
	ConstantContents * c2 = new ConstantContents();
	RegisterContents * c3 = new RegisterContents();
	int type;
	switch (is.get()) {
		case FILE_FORMAT_OPCODE_TYPE:
			c1->code(get_type<unsigned int>(is));
			code.contents(c1);
			code.type(OP);
			delete c2;
			delete c3;
		break;

		case FILE_FORMAT_CONST_TYPE:
			type = is.get();
			if (type == FILE_FORMAT_CONST_INT)
				c2->set(get_type<int>(is));
			else if (type == FILE_FORMAT_CONST_FLOAT)
				c2->set(get_type<double>(is));
			code.contents(c2);
			code.type(CONSTANT);
			delete c1;
			delete c3;
		break;

		case FILE_FORMAT_REGISTER_TYPE:
			c3->index(get_type<int>(is));
			code.contents(c3);
			code.type(REGISTER);
			delete c1;
			delete c2;
		break;
	};
	return is;
};

void get_operations(std::istream_iterator<ByteCode> & begin, std::istream_iterator<ByteCode> & end, std::vector<PrimedRegister *> & results) {
	std::vector<ByteCode> codes;
	std::copy(begin, end, std::back_inserter(codes));
	std::vector<ByteCode>::iterator code = codes.begin();
	RegisterPrimer primer;
	OpCodeContents * contents;
	while (code != codes.end()) {
		ByteCode & bc = *code;
		switch (bc.type()) {
			case OP:
				if (primer.isDone()) {
					results.push_back(primer.op);
				}
				contents = static_cast<OpCodeContents *>(bc.contents());
				primer.addOp(contents->code());
			break;

			default:
				primer.addRegister(bc);
			break;
		}
		code++;
	}
	if (primer.isDone()) {
		results.push_back(primer.op);
	}
};
