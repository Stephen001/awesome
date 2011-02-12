/*
 * Execute.h
 *
 *  Created on: Aug 6, 2010
 *      Author: stephen001
 */

#ifndef EXECUTE_H_
#define EXECUTE_H_

#include <vector>
#include <DLLProcess.h>
#include <format/PrimedRegister.h>
#include <Register.h>

#define NUM_REGISTERS 4

class DLL_DECL Executor {
public:
	Executor();
	~Executor();
	Register * convert(ByteCode & code);
	void execute(PrimedRegister & op);
	void print_registers();
private:
	struct RegisterGroup<NUM_REGISTERS> registers;
};

#endif /* EXECUTE_H_ */
