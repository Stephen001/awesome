/*
 * Execute.cpp
 *
 *  Created on: Dec 31, 2010
 *      Author: stephen001
 */

#include <core/Execute.h>
#include <format/RegisterInstruction.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class Convert : public std::unary_function<Register *, ByteCode &> {
public:
	Convert(Executor & executor) : executor(executor) {};
	Register * operator() (ByteCode & code) {
		return this->executor.convert(code);
	};
private:
	Executor & executor;
};

Executor::Executor() {
	for (int i = 0; i < NUM_REGISTERS; i++) {
		registers.values[i] = new Register();
	}
};

Executor::~Executor() {};

void Executor::execute(PrimedRegister & op) {
	Convert convertor(*this);
	std::vector<ByteCode> & args = op.registers();
	std::vector<Register *> registers;
	registers.reserve(args.size());
	transform(args.begin(), args.end(), registers.begin(), convertor);
	op.op().execute(registers);
};

void Executor::print_registers() {
	for (int i = 0; i < NUM_REGISTERS; i++) {
		std::cerr << "Position " << i << " = " << registers.values[i]->get<double>() << std::endl;
	}
	std::cerr << std::endl;
};

Register * Executor::convert(ByteCode & code) {
	if (code.type() == CONSTANT) {
		return &(static_cast<ConstantContents *>(code.contents())->get_register());
	} else {
		return registers.values[static_cast<RegisterContents *>(code.contents())->index()];
	}
}
