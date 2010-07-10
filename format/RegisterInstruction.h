/*
 * RegisterInstruction.h
 *
 *  Created on: Jun 27, 2010
 *      Author: stephen001
 */

#ifndef REGISTERINSTRUCTION_H_
#define REGISTERINSTRUCTION_H_

#include <DLLProcess.h>
#include <Register.h>
#include <format/ReadInstruction.h>

class DLL_DECL ConstantContents : public ByteCodeContents {
public:
	ConstantContents();
	virtual ~ConstantContents();
	Register & get_register();
	template <typename T>
	void set(T value) { __register.set(value); }
private:
	Register __register;
};

class DLL_DECL RegisterContents : public ByteCodeContents {
public:
	RegisterContents();
	virtual ~RegisterContents();
	int index();
	void index(int index);
private:
	int __index;
};

#endif /* REGISTERINSTRUCTION_H_ */
