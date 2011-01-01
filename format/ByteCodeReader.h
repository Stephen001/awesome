/*
 * ByteCodeReader.h
 *
 *  Created on: Dec 31, 2010
 *      Author: stephen001
 */

#ifndef BYTECODEREADER_H_
#define BYTECODEREADER_H_

#include <DLLProcess.h>
#include <format/ReadInstruction.h>
#include <format/PrimedRegister.h>
#include <iostream>
#include <iterator>
#include <vector>

void DLL_DECL get_operations(std::istream_iterator<ByteCode> & begin, std::istream_iterator<ByteCode> & end, std::vector<PrimedRegister *> & results);

#endif /* BYTECODEREADER_H_ */
