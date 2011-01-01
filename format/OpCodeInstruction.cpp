/*
 * OpCodeInstruction.cpp
 *
 *  Created on: Jul 29, 2010
 *      Author: stephen001
 */

#include <format/OpCodeInstruction.h>

OpCodeContents::OpCodeContents() {}

OpCodeContents::~OpCodeContents() {}

void OpCodeContents::code(unsigned int code) {
	__code = code;
}

unsigned int OpCodeContents::code() {
	return __code;
}
