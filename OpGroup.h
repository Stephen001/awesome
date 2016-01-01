/*
 * OpGroup.h
 *
 *  Created on: 21 Feb 2010
 *      Author: Administrator
 */

#ifndef OPGROUP_H_
#define OPGROUP_H_

#include <DLLProcess.h>
#include <OpCode.h>

#define GET_GROUP_CODE(OPCODE) ((OPCODE) >> 16)
#define GET_OP_CODE(OPCODE) ((OPCODE) & 0x0000FFFF)

class DLL_DECL OpGroup {
public:
	OpGroup(const char * name, unsigned short code);
	virtual ~OpGroup() {};
	inline unsigned short code() { return __code; };
	inline bool matches(unsigned int op) { return __code == GET_GROUP_CODE(op); };
	inline const char * name() { return __name; };
	virtual Op & get(unsigned int op) { return OpGroup::error; };
protected:
	inline unsigned short opcode(unsigned int op) { return GET_OP_CODE(op); };
private:
	unsigned short 	__code;
	const char * 	__name;
	static Op error;
};

#define OPGROUP_INHERITED_DECLARATION(SIZE) public:\
	Op & get(unsigned int op);\
private:\
	Op * values[(SIZE)];

#define OPGROUP_CLEAN_INHERITED_DECLARATION for (unsigned int i = 0; i < (sizeof(values) / sizeof(Op *)); i++) {\
	delete values[i];\
};

#define OPGROUP_ASSIGN_OP(NAME, POSITION) values[POSITION] = new NAME();

#define OPGROUP_GET_DEFINITION(IMPL) Op & IMPL::get(unsigned int op) {\
	return *values[GET_OP_CODE(op)];\
};

#undef GET_GROUP_CODE

#endif /* OPGROUP_H_ */
