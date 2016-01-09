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
	krDetector(char* filename);
	int DoStep(cv::Mat *img_p);
	virtual ~krDetector();

	cv::CascadeClassifier cascade;
};

} /* namespace korbinian */

#endif /* KRDETECTOR_H_ */
