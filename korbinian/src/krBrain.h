/*
 * krBrain.h
 *
 *  Created on: 2015/12/05
 *      Author: katsuya
 */

#ifndef KRBRAIN_H_
#define KRBRAIN_H_
#include "krShm.h"

namespace korbinian {

class krBrain {
public:
	krBrain(char*);
	virtual ~krBrain();
private:
	KRBRAIN	*sm;
	int size;
};
} /* namespace krbrain */

#endif /* KRBRAIN_H_ */
