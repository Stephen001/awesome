/*
 * OpCodeInstruction.h
 *
 *  Created on: Jul 29, 2010
 *      Author: stephen001
 */

#ifndef OPCODEINSTRUCTION_H_
#define OPCODEINSTRUCTION_H_

#include <format/ReadInstruction.h>

class DLL_DECL OpCodeContents: public ByteCodeContents {
public:
	OpCodeContents();
	virtual ~OpCodeContents();
	void code(unsigned int code);
	unsigned int code();
private:
	unsigned int __code;
};

#endif /* OPCODEINSTRUCTION_H_ */
