/*
 * MathOps.cpp
 *
 *  Created on: 11 Feb 2010
 *      Author: Administrator
 */

#include <core/MathOps.h>

#define EXECUTE_BINARY(IMPL, OPERAND) void IMPL::execute(std::vector<Register *> & regs) {\
	RegisterType type = regs[0]->state();\
	int r1 = 0;\
	double r2 = 0;\
	switch (type) {\
		case INTEGER:\
			r1 = regs[1]->get<int>() +\
				 regs[2]->get<int>();\
			regs[0]->set<int>(r1);\
		break;\
		case FLOATING_POINT:\
			r2 = regs[1]->get<double>() +\
				 regs[2]->get<double>();\
			regs[0]->set<double>(r2);\
		break;\
	};\
};

#define EXECUTE_IN_PLACE(IMPL, OPERAND)  void IMPL::execute(std::vector<Register *> & regs) {\
	RegisterType type = regs[0]->state();\
	int r1 = 0;\
	double r2 = 0;\
	switch (type) {\
		case INTEGER:\
			r1 = regs[0]->get<int>() +\
				 regs[1]->get<int>();\
			regs[0]->set<int>(r1);\
		break;\
		case FLOATING_POINT:\
			r2 = regs[0]->get<double>() +\
				 regs[1]->get<double>();\
			regs[0]->set<double>(r2);\
		break;\
	};\
};

void AssignOp::execute(std::vector<Register *> & registers) {
	switch (registers[0]->state()) {
		case INTEGER:
			registers[0]->set<int>(registers[1]->get<int>());
		break;

		case FLOATING_POINT:
			registers[0]->set<double>(registers[1]->get<double>());
		break;
	}
};

EXECUTE_BINARY(AddOp, +)
EXECUTE_IN_PLACE(AddInPlaceOp, +)
EXECUTE_BINARY(SubtractOp, -)
EXECUTE_IN_PLACE(SubtractInPlaceOp, -)

MathOpGroup::MathOpGroup() : OpGroup("MathOps", 1) {
	OPGROUP_ASSIGN_OP(AssignOp,			 0);
	OPGROUP_ASSIGN_OP(AddOp, 			 1);
	OPGROUP_ASSIGN_OP(AddInPlaceOp, 	 2);
	OPGROUP_ASSIGN_OP(SubtractOp, 		 3);
	OPGROUP_ASSIGN_OP(SubtractInPlaceOp, 4);
};

OPGROUP_GET_DEFINITION(MathOpGroup)
