/*
 * krReportFrame.h
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#ifndef KRREPORTFRAME_H_
#define KRREPORTFRAME_H_

#include "opencv2/opencv.hpp"
#include "krBlock.h"

namespace korbinian {

class krReportFrame: public krBlock {
public:
	krReportFrame(char* windowName);
	int doStep(cv::Mat *frame_p);
	virtual ~krReportFrame();

private:
};

} /* namespace krbrain */

#endif /* KRREPORTFRAME_H_ */
