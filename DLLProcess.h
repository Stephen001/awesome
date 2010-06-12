/*
 * DLLProcess.h
 *
 *  Created on: 11 Feb 2010
 *      Author: Administrator
 */

#ifndef DLLPROCESS_H_
#define DLLPROCESS_H_

#ifdef _WIN32
	#ifdef AWESOME_DLL_IMPORT
		#define DLL_DECL __declspec(dllimport)
	#else
		#define DLL_DECL __declspec(dllexport)
	#endif
#else
#define DLL_DECL
#endif

#endif /* DLLPROCESS_H_ */
