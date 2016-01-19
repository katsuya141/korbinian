/*
 * krDetector.h
 *
 *  Created on: 2016/01/07
 *      Author: katsuya
 */

#ifndef KRDETECTOR_H_
#define KRDETECTOR_H_

#include "opencv2/opencv.hpp"
#include <time.h>     // for clock()
#include "krBlock.h"

namespace korbinian {

class krDetector: public krBlock {
public:
	krDetector(cv::Mat *SourceFrame_p, cv::String filename);
	int doStep();
	cv::Mat *drawResult(cv::Mat *SourceFrame_p);
	std::vector<cv::Rect> *getDetects();
	virtual ~krDetector();

	cv::CascadeClassifier cascade;	// 検出器
	std::vector<cv::Rect> detects;	//検出結果
	cv::Mat *SourceFrame_p;
};

} /* namespace korbinian */

#endif /* KRDETECTOR_H_ */
