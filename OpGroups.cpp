/*
 * Opgroups.cpp
 *
 *  Created on: Aug 6, 2010
 *      Author: stephen001
 */

#include <OpGroup.h>
#include <OpGroups.h>
#include <map>

#define GET_GROUP_CODE(OPCODE) ((OPCODE) >> 16)

std::map<unsigned short, OpGroup *> groups;

void initialise_groups() {
	if (groups.size() == 0) {
		MathOpGroup * mathGroup = new MathOpGroup();
		groups[mathGroup->code()] = mathGroup;
	}
}

Op & get_op(unsigned int code) {
	initialise_groups();
	return groups[GET_GROUP_CODE(code)]->get(code);
}
