/*
 * ReadInstruction.cpp
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#include <format/ReadInstruction.h>

ByteCodeContents::ByteCodeContents() {};

ByteCodeContents::~ByteCodeContents() {};

ByteCode::ByteCode() {
	__contents = new ByteCodeContents();
};

ByteCode::~ByteCode() {
	//delete __contents;
};

ByteCodeContents * const ByteCode::contents() {
	return __contents;
};

void ByteCode::contents(ByteCodeContents * contents) {
	delete __contents;
	__contents = contents;
};

CodeType ByteCode::type() {
	return __type;
};

void ByteCode::type(CodeType type) {
	__type = type;
};
