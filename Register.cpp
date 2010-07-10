/*
 * Register.cpp
 *
 *  Created on: 21 Mar 2010
 *      Author: Administrator
 */

#include <Register.h>

template <>
int Register::get<int>() {
	return __state == INTEGER ? __value.as_int : static_cast<int>(__value.as_float);
};

template <>
double Register::get<double>() {
	return __state == FLOATING_POINT ? __value.as_float : static_cast<double>(__value.as_int);
};

template <>
void Register::set<int>(int value) {
	__state 		= INTEGER;
	__value.as_int 	= value;
};

template <>
void Register::set<double>(double value) {
	__state 			= FLOATING_POINT;
	__value.as_float 	= value;
};

RegisterType Register::state() {
	return __state;
};
