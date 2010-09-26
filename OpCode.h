/*
 * OpCode.h
 *
 *  Created on: 9 Feb 2010
 *      Author: Administrator
 */

#ifndef OPCODE_H_
#define OPCODE_H_

#include <DLLProcess.h>
#include <istream>

struct Register;

class DLL_DECL Op {
	virtual void execute( Register ** registers );
	friend std::istream & operator>>(std::istream & is, Op & op);
};
#endif /* OPCODE_H_ */
