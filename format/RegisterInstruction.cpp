/*
 * RegisterInstruction.cpp
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#include <format/RegisterInstruction.h>

ConstantContents::ConstantContents() : ByteCodeContents() {};

ConstantContents::~ConstantContents() {}

RegisterContents::RegisterContents() : ByteCodeContents() {};

RegisterContents::~RegisterContents() {};

Register & ConstantContents::get_register() {
	return __register;
};

int RegisterContents::index() {
	return __index;
};

void RegisterContents::index(int index) {
	__index = index;
};
