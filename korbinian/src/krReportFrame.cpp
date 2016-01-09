/*
 * krReportFrame.cpp
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */
#include "opencv2/opencv.hpp"

#include "krReportFrame.h"

namespace korbinian {

krReportFrame::krReportFrame() {

}

int krReportFrame::DoStep(cv::Mat *frame_p) {

    cv::imshow("window", *frame_p);//画像を表示．

	int key = cv::waitKey(1);

	if(key == 1048691)//sが押されたとき
    {
        //フレーム画像を保存する．
        cv::imwrite("img.png", *frame_p);
    }

	return true;
}

krReportFrame::~krReportFrame() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace krbrain */
