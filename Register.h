/*
 * Register.h
 *
 *  Created on: 9 Feb 2010
 *      Author: Administrator
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include "DLLProcess.h"

enum RegisterType {
	INTEGER, FLOATING_POINT
};

union RegisterValue {
	int 	as_int;
	double 	as_float;
};

class DLL_DECL Register {
public:
	template <typename T>
	T 			 get();
	template <typename T>
	void		 set(T value);
	RegisterType state();
private:
	RegisterType 	__state;
	RegisterValue 	__value;
};

template <unsigned short T>
struct DLL_DECL RegisterGroup {
	Register * values[T];
};

#endif /* REGISTER_H_ */
