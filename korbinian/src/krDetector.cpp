/*
 * krDetector.cpp
 *
 *  Created on: 2016/01/07
 *      Author: katsuya
 */

#include "krDetector.h"

namespace korbinian {

krDetector::krDetector(char* filename) {
	  if(!this->cascade.load(filename)){
		  //return -1; //カスケードファイルロードエラー
		  ;
	  }
}
int krDetector::DoStep(cv::Mat *img_p) {
    // 処理時間計測基準値
    clock_t clock_base=clock();

    //----------------------------------------------------------------------------
    //scaleの値を用いて元画像を縮小、符号なし8ビット整数型，1チャンネル(モノクロ)の画像を格納する配列を作成
    double scale = 4.0;


    // グレースケール画像に変換
    cv::Mat gray;
    cv::cvtColor(*img_p, gray, CV_BGR2GRAY);
    cv::Mat smallImg(cv::saturate_cast<int>((*img_p).rows/scale), cv::saturate_cast<int>((*img_p).cols/scale), CV_8UC1);    // 処理時間短縮のために画像を縮小
    cv::resize(gray, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);
    cv::equalizeHist( smallImg, smallImg);

    std::vector<cv::Rect> faces;
    /// マルチスケール（顔）探索xo
    // 画像，出力矩形，縮小スケール，最低矩形数，（フラグ），最小矩形
    cascade.detectMultiScale(smallImg, faces, 1.1, 2, CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
    //cascade.detectMultiScale(smallImg, faces);

    // 結果の描画
    std::vector<cv::Rect>::const_iterator r = faces.begin();
    for(; r != faces.end(); ++r)
    {
      cv::Point center;
      int radius;
      center.x = cv::saturate_cast<int>((r->x + r->width*0.5)*scale);
      center.y = cv::saturate_cast<int>((r->y + r->height*0.5)*scale);
      radius = cv::saturate_cast<int>((r->width + r->height)*0.25*scale);
      cv::circle( *img_p, center, radius, cv::Scalar(80,80,255), 3, 8, 0 );
    }

      //cv::namedWindow("result", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
      cv::imshow( "Detector", *img_p );
      //cv::waitKey(0);

    //----------------------------------------------------------------------------
    // 処理時間計測
    this->laptime=clock()-clock_base;
    return 0;

}

krDetector::~krDetector() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace korbinian */
