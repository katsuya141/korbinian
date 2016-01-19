/*
 * krReportFrame.cpp
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */
/**
 * @file    Addition.c
 * @brief   足し算を行うサンプルプログラム
 *
 * @author  日電　太郎
 * @date    2007-11-30
 *
 */
#include "opencv2/opencv.hpp"

#include "krReportFrame.h"

namespace korbinian {

/**
 * @brief   基数を設定する
 *
 * @param   obj 該当のAdditionオブジェクト
 * @param   _base 基数に設定する数
 */
krReportFrame::krReportFrame(char* windowName) {
	this->name= windowName;
}

int krReportFrame::doStep(cv::Mat *frame_p) {

    cv::imshow(this->name, *frame_p);//画像を表示．

	int key = cv::waitKey(1);

//	if(key == 1048691)//sが押されたとき
	if(key == 115)//sが押されたとき
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
