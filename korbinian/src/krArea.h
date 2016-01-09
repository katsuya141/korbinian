/*
 * krArea.h
 *
 *  Created on: 2015/12/05
 *      Author: katsuya
 */

#ifndef KRAREA_H_
#define KRAREA_H_
#include "krShm.h"
#include "krBrain.h"

namespace korbinian {

class krArea {
public:
	krArea(krBrain *brain);
	virtual ~krArea();
private:
	KRBRAIN	*sm;
	int size;
};

} /* namespace krbrain */

#endif /* KRAREA_H_ */
