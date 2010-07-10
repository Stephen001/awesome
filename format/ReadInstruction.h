/*
 * ReadInstruction.h
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#ifndef READINSTRUCTION_H_
#define READINSTRUCTION_H_

#include <DLLProcess.h>
#include <istream>

DLL_DECL enum CodeType {
	OP, REGISTER, CONSTANT
};

class DLL_DECL ByteCodeContents {
public:
	ByteCodeContents();
	virtual ~ByteCodeContents();
};

class DLL_DECL ByteCode {
public:
	ByteCode();
	virtual ~ByteCode();
	ByteCodeContents * const contents();
	void contents(ByteCodeContents * contents);
	CodeType type();
	void type(CodeType type);
	friend std::istream & operator>>(std::istream & is, ByteCode & code);
private:
	ByteCodeContents * __contents;
	CodeType __type;
};

#endif /* READINSTRUCTION_H_ */
