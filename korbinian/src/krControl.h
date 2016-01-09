/*
 * krControl.h
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#ifndef KRCONTROL_H_
#define KRCONTROL_H_
#include <time.h>     // for clock()
#include "krBlock.h"

namespace korbinian {

class krControl: public krBlock {
public:
	krControl();
	int DoStep();
	int getTotaltime();
	virtual ~krControl();

	clock_t clocktime;
	clock_t totaltime;
};

} /* namespace krbrain */

#endif /* KRCONTROL_H_ */
