/*
 * krMonitor.h
 *
 *  Created on: 2016/01/06
 *      Author: katsuya
 */

#ifndef KRMONITOR_H_
#define KRMONITOR_H_

#include "opencv2/opencv.hpp"
#include "krBlock.h"

namespace korbinian {

class krMonitor: public krBlock {
public:
	krMonitor();
	void Print(int x,int y, const char* format, ...);
	int DoStep();
	virtual ~krMonitor();

	cv::Mat img;
};

} /* namespace krbrain */

#endif /* KRMONITOR_H_ */
