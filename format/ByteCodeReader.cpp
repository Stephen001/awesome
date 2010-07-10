/*
 * ByteCodeReader.cpp
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#include <format/ReadInstruction.h>
#include <format/RegisterInstruction.h>

#define FILE_FORMAT_OPCODE_TYPE 	0
#define FILE_FORMAT_REGISTER_TYPE 	1
#define FILE_FORMAT_CONST_TYPE 		2

#define FILE_FORMAT_CONST_INT		0
#define FILE_FORMAT_CONST_FLOAT		1

template<typename T>
T get_type(std::istream & is) {
	T result = 0;
	is.read(reinterpret_cast<char *>(&result), sizeof(T));
	return result;
}

std::istream & operator >>(std::istream & is, ByteCode & code) {
	ConstantContents * c1 = new ConstantContents();
	RegisterContents * c2 = new RegisterContents();
	int type;
	switch (is.get()) {
		case FILE_FORMAT_CONST_TYPE:
			type = is.get();
			if (type == FILE_FORMAT_CONST_INT)
				c1->set(get_type<int>(is));
			else if (type == FILE_FORMAT_CONST_FLOAT)
				c1->set(get_type<double>(is));
			code.contents(c1);
			code.type(CONSTANT);
		break;

		case FILE_FORMAT_REGISTER_TYPE:
			c2->index(get_type<int>(is));
			code.contents(c2);
			code.type(REGISTER);
		break;
	};
	return is;
};
