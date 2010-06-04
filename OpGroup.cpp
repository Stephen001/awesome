/*
 * OpGroup.cpp
 *
 *  Created on: 21 Feb 2010
 *      Author: Administrator
 */

#include "OpGroup.h"

Op OpGroup::error;

OpGroup::OpGroup(const char * name, unsigned short code)
	: __code(code), __name(name) {};
