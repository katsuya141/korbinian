/*
 * krCamera.cpp
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#include "opencv2/opencv.hpp"
#include "krCamera.h"

namespace korbinian {

krCamera::krCamera(int deviceno) {
	// TODO 自動生成されたコンストラクター・スタブ

    this->cap.open(deviceno);//デバイスのオープン
    //cap.open(0);//こっちでも良い．

    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        //return -1;
    }
	cv::Mat m1;
	/*
    this->cap >> m1; // get a new frame from camera
    // 行数
     std::cout << "rows:" << m1.rows <<std::endl;
     // 列数
     std::cout << "cols:" << m1.cols << std::endl;
     // 次元数
     std::cout << "dims:" << m1.dims << std::endl;
     // サイズ（2次元の場合）
     std::cout << "size[]:" << m1.size().width << "," << m1.size().height << std::endl;
     // ビット深度ID
     std::cout << "depth (ID):" << m1.depth() << "(=" << CV_64F << ")" << std::endl;
     // チャンネル数
     std::cout << "channels:" << m1.channels() << std::endl;
     // （複数チャンネルから成る）1要素のサイズ [バイト単位]
     std::cout << "elemSize:" << m1.elemSize() << "[byte]" << std::endl;
     // 1要素内の1チャンネル分のサイズ [バイト単位]
     std::cout << "elemSize1 (elemSize/channels):" << m1.elemSize1() << "[byte]" << std::endl;
     // 要素の総数
     std::cout << "total:" << m1.total() << std::endl;
     // ステップ数 [バイト単位]
     std::cout << "step:" << m1.step << "[byte]" << std::endl;
     // 1ステップ内のチャンネル総数
     std::cout << "step1 (step/elemSize1):" << m1.step1()  << std::endl;
     // データは連続か？
     std::cout << "isContinuous:" << (m1.isContinuous()?"true":"false") << std::endl;
     // 部分行列か？
     std::cout << "isSubmatrix:" << (m1.isSubmatrix()?"true":"false") << std::endl;
     // データは空か？
     std::cout << "empty:" << (m1.empty()?"true":"false") << std::endl;
     */
}

int krCamera::DoStep() {
    // 処理時間計測基準値
    clock_t clock_base=clock();

    this->cap >> this->frame; // get a new frame from camera

    // 処理時間計測
    this->laptime=clock()-clock_base;
    return 0;

}

krCamera::~krCamera() {
    cv::destroyAllWindows();
    //return 0;
}

} /* namespace krbrain */
