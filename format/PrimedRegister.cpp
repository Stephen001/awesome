/*
 * PrimedRegister.cpp
 *
 *  Created on: Aug 6, 2010
 *      Author: stephen001
 */

#include "PrimedRegister.h"
#include <OpGroups.h>

PrimedRegister::PrimedRegister(unsigned int code) : __op(get_op(code)) {
	__registers.reserve(__op.registers());
}

PrimedRegister::~PrimedRegister() {}

void PrimedRegister::add(ByteCode & contents) {
	__registers.push_back(contents);
}

unsigned int PrimedRegister::registers() {
	return __op.registers();
}

ByteCode & PrimedRegister::get(int registerIndex) {
	return __registers[registerIndex];
};
