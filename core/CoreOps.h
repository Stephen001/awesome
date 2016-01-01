/*
 * CoreOpGroup.h
 *
 *  Created on: 31 May 2010
 *      Author: Administrator
 */

#ifndef COREOPS_H_
#define COREOPS_H_

#include <OpGroup.h>

class DLL_DECL CoreOpGroup: public OpGroup {
public:
	CoreOpGroup();
	~CoreOpGroup();
	OPGROUP_INHERITED_DECLARATION(1);
};

#endif /* COREOPS_H_ */
