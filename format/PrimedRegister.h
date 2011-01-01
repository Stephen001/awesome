/*
 * PrimedRegister.h
 *
 *  Created on: Aug 6, 2010
 *      Author: stephen001
 */

#ifndef PRIMEDREGISTER_H_
#define PRIMEDREGISTER_H_

#include <OpCode.h>
#include <format/ReadInstruction.h>
#include <vector>

class PrimedRegister {
public:
	PrimedRegister(unsigned int opcode);
	virtual ~PrimedRegister();
	void add(ByteCode & contents);
	unsigned int registers();
	ByteCode & get(int registerIndex);
	Op & op() { return __op; };
private:
	Op & 				  __op;
	std::vector<ByteCode> __registers;
};

#endif /* PRIMEDREGISTER_H_ */
