/*
 * CoreOps.cpp
 *
 *  Created on: 31 May 2010
 *      Author: Administrator
 */

#include <core/CoreOps.h>

CoreOpGroup::CoreOpGroup() : OpGroup("CoreOps", 0) {};

CoreOpGroup::~CoreOpGroup() {
	OPGROUP_CLEAN_INHERITED_DECLARATION
}

OPGROUP_GET_DEFINITION(CoreOpGroup)
