/*
 * MathOps.cpp
 *
 *  Created on: 11 Feb 2010
 *      Author: Administrator
 */

#include <core/MathOps.h>

#define EXECUTE_BINARY(IMPL, OPERAND) void IMPL::execute() {\
	RegisterType type = __registers.values[0]->state();\
	int r1 = 0;\
	double r2 = 0;\
	switch (type) {\
		case INTEGER:\
			r1 = __registers.values[1]->get<int>() +\
				__registers.values[2]->get<int>();\
			__registers.values[0]->set<int>(r1);\
		break;\
		case FLOATING_POINT:\
			r2 = __registers.values[1]->get<double>() +\
				__registers.values[2]->get<double>();\
			__registers.values[0]->set<double>(r2);\
		break;\
	};\
};

#define EXECUTE_IN_PLACE(IMPL, OPERAND)  void IMPL::execute() {\
	RegisterType type = __registers.values[0]->state();\
	int r1 = 0;\
	double r2 = 0;\
	switch (type) {\
		case INTEGER:\
			r1 = __registers.values[0]->get<int>() +\
				__registers.values[1]->get<int>();\
			__registers.values[0]->set<int>(r1);\
		break;\
		case FLOATING_POINT:\
			r2 = __registers.values[0]->get<double>() +\
				__registers.values[1]->get<double>();\
			__registers.values[0]->set<double>(r2);\
		break;\
	};\
};

OPCODE_ASSIGN_DEFINITION(AssignOp, 3)
OPCODE_ASSIGN_DEFINITION(AddOp, 3)
OPCODE_ASSIGN_DEFINITION(AddInPlaceOp, 2)
OPCODE_ASSIGN_DEFINITION(SubtractOp, 3)
OPCODE_ASSIGN_DEFINITION(SubtractInPlaceOp, 2)

EXECUTE_IN_PLACE(AssignOp, =)
EXECUTE_BINARY(AddOp, +)
EXECUTE_IN_PLACE(AddInPlaceOp, +=)
EXECUTE_BINARY(SubtractOp, -)
EXECUTE_IN_PLACE(SubtractInPlaceOp, -=)

MathOpGroup::MathOpGroup() : OpGroup("MathOps", 1) {
	OPGROUP_ASSIGN_OP(AssignOp,			 0);
	OPGROUP_ASSIGN_OP(AddOp, 			 1);
	OPGROUP_ASSIGN_OP(AddInPlaceOp, 	 2);
	OPGROUP_ASSIGN_OP(SubtractOp, 		 3);
	OPGROUP_ASSIGN_OP(SubtractInPlaceOp, 4);
};

OPGROUP_GET_DEFINITION(MathOpGroup)
