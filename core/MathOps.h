/*
 * MathOps.h
 *
 *  Created on: 11 Feb 2010
 *      Author: Administrator
 */

#ifndef MATHOPS_H_
#define MATHOPS_H_

#include <OpCode.h>
#include <Register.h>
#include <OpGroup.h>

class DLL_DECL MathOpGroup : public OpGroup
{
public:
	MathOpGroup();
	OPGROUP_INHERITED_DECLARATION(5);
};

#define NEW_MATHOP(NAME) class DLL_DECL NAME : public Op\
{\
	void execute( std::vector<Register *> & registers );\
};

NEW_MATHOP(AssignOp)
NEW_MATHOP(AddOp)
NEW_MATHOP(AddInPlaceOp)
NEW_MATHOP(SubtractOp)
NEW_MATHOP(SubtractInPlaceOp)

#undef NEW_MATHOP

#endif /* MATHOPS_H_ */
