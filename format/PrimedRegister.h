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

class DLL_DECL PrimedRegister {
public:
	PrimedRegister(unsigned int opcode);
	virtual ~PrimedRegister();
	void add(ByteCode & contents);
	std::vector<ByteCode> & registers();
	Op & op();
private:
	Op & 				  __op;
	std::vector<ByteCode> __registers;
};

#endif /* PRIMEDREGISTER_H_ */
