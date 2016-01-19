/*
 * krCamera.h
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#ifndef KRCAMERA_H_
#define KRCAMERA_H_

#include "opencv2/opencv.hpp"
#include "krBlock.h"

namespace korbinian {

class krCamera: public krBlock {
public:
	krCamera(int deviceno);
	int doStep();
	cv::Mat *getFrameP();
	virtual ~krCamera();
private:
	cv::Mat frame;
	cv::VideoCapture cap;
};

} /* namespace krbrain */

#endif /* KRCAMERA_H_ */
