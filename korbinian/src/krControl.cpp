/*
 * krControl.cpp
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#include "opencv2/opencv.hpp"
#include "krControl.h"

namespace korbinian {

krControl::krControl() {
	// TODO 自動生成されたコンストラクター・スタブ

}

int krControl::doStep() {
	int key = cv::waitKey(1);
	if(key>0)
		printf("%d\n",key);
	//    if(key == 1048689)//qボタンが押されたとき
	if(key == 113)//qボタンが押されたとき
    {
        return false;//シミュレーションループから抜ける．
    }
    clock_t clock_now=clock();
    this->totaltime =(clock_now - this->clocktime)/( CLOCKS_PER_SEC/1000);
    this->clocktime =clock_now;
    return true;
}
int krControl::getTotaltime() {
	return this->totaltime;
}

krControl::~krControl() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace krbrain */
