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
#include <vector>

struct Register;

class DLL_DECL Op {
public:
	Op() {};
	virtual void execute(std::vector<Register *> & regs) {};
	virtual inline unsigned short registers() { return 0; };
	friend std::istream & operator>>(std::istream & is, Op & op);
};

#define OPCODE_INHERITED_DECLARATION(SIZE) public:\
	void execute(Register ** regs);\
	inline unsigned short registers() { return (SIZE); };\

#endif /* OPCODE_H_ */
