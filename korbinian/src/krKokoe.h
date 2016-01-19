/*
 * krKokoe.h
 *
 *  Created on: 2016/01/07
 *      Author: katsuya
 */

#ifndef KRKOKOE_H_
#define KRKOKOE_H_
#include "opencv2/opencv.hpp"
#include <time.h>     // for clock()
#include "krBlock.h"

namespace korbinian {

class krKokoe: public krBlock {
public:
	krKokoe();
	void Print(int y, const char* format, ...);
	int doStep();
	virtual ~krKokoe();

	cv::Mat img;
	clock_t clocktime;
	clock_t interval=10;
};

} /* namespace korbinian */

#endif /* KRKOKOE_H_ */
