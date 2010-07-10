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
public:
	Op() : _added(0) {};
	virtual void assign(Register * reg) {};
	virtual void execute() {};
	virtual inline unsigned short registers() { return 0; };
	friend std::istream & operator>>(std::istream & is, Op & op);
protected:
	unsigned short _added;
};

#define OPCODE_INHERITED_DECLARATION(SIZE) public:\
	void execute();\
	void assign(Register * reg);\
	inline unsigned short registers() { return (SIZE); };\
private:\
	RegisterGroup<(SIZE)> __registers;

#define OPCODE_ASSIGN_DEFINITION(IMPL, MAX) void IMPL::assign(Register * reg) { \
	if (_added > (MAX)) return;\
	__registers.values[_added++] = reg;\
};

#endif /* OPCODE_H_ */
