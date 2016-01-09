/*
 * krMonitor.cpp
 *
 *  Created on: 2016/01/06
 *      Author: katsuya
 */
#include <stdarg.h>
#include "krMonitor.h"

namespace korbinian {

krMonitor::krMonitor() {
	  this->img = cv::Mat::zeros(500, 500, CV_8UC3);
}
void krMonitor::Print(int x, int y, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    char* allocatedBuffer;
    int size = vasprintf(&allocatedBuffer, format, ap);
    va_end(ap);
    cv::rectangle(this->img, cv::Point(x*20,y*20-10), cv::Point(x*20+200,y*20), cv::Scalar(200,0,0), -1, CV_AA);
    cv::putText(this->img, allocatedBuffer, cv::Point(x*20,y*20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0,0,200), 1, CV_AA);
    free(allocatedBuffer);
}

int krMonitor::DoStep() {
	  cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	  cv::imshow("drawing", this->img);

	return true;
}

krMonitor::~krMonitor() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace krbrain */
