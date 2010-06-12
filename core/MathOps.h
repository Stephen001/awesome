/*
 * MathOps.h
 *
 *  Created on: 11 Feb 2010
 *      Author: Administrator
 */

#ifndef MATHOPS_H_
#define MATHOPS_H_

#include "../OpCode.h"
#include "../Register.h"
#include "../OpGroup.h"

class DLL_DECL MathOpGroup : public OpGroup
{
public:
	MathOpGroup();
	OPGROUP_INHERITED_DECLARATION(5);
};

#define NEW_MATHOP(NAME, ARGS) class DLL_DECL NAME : public Op\
{\
	OPCODE_INHERITED_DECLARATION(ARGS)\
};

NEW_MATHOP(AssignOp, 2)
NEW_MATHOP(AddOp, 3)
NEW_MATHOP(AddInPlaceOp, 2)
NEW_MATHOP(SubtractOp, 3)
NEW_MATHOP(SubtractInPlaceOp, 2)

#undef NEW_MATHOP

#endif /* MATHOPS_H_ */
