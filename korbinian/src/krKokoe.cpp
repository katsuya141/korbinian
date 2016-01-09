/*
 * krKokoe.cpp
 *
 *  Created on: 2016/01/07
 *      Author: katsuya
 */
#include <stdarg.h>
#include "krKokoe.h"

namespace korbinian {

krKokoe::krKokoe(){
	  this->img = cv::Mat::zeros(500, 500, CV_8UC3);
	  this->clocktime=clock();
}
void krKokoe::Print(int x, const char* format, ...) {



	va_list ap;
    va_start(ap, format);
    char* allocatedBuffer;
    int size = vasprintf(&allocatedBuffer, format, ap);
    va_end(ap);

    clock_t clock_now=clock();
    if(this->interval < (clock_now - this->clocktime)/( CLOCKS_PER_SEC/1000)){
//        cv::rectangle(this->img, cv::Point(x*20,500-20), cv::Point(x*20+200,500), cv::Scalar(200,0,0), -1, CV_AA);
        this->clocktime =clock_now;
        cv::Size patch_sie(500, 500);
        cv::Point2f center(250.0 - 0.5, 250.0-0.5 + 5);
        // 矩形領域ピクセル値をサブピクセル精度で取得
        cv::getRectSubPix(this->img, patch_sie, center, this->img);

    }
    cv::putText(this->img, allocatedBuffer, cv::Point(x*20,500-5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0,0,200), 1, CV_AA);
    free(allocatedBuffer);


}

int krKokoe::DoStep() {
	  cv::namedWindow("kokoe", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	  cv::imshow("kokoe", this->img);

	return true;
}

krKokoe::~krKokoe() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace korbinian */
