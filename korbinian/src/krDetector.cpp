/*
 * krDetector.cpp
 *
 *  Created on: 2016/01/07
 *      Author: katsuya
 */

#include "krDetector.h"

namespace korbinian {

krDetector::krDetector(cv::Mat *frame_p, cv::String filename) {
	if(!this->cascade.load(filename)){
		  //return -1; //カスケードファイルロードエラー
		  ;
	  }
	this->SourceFrame_p = frame_p;
}
int krDetector::doStep() {
    // 処理時間計測基準値
    clock_t clock_base=clock();
    //----------------------------------------------------------------------------
    //scaleの値を用いて元画像を縮小、符号なし8ビット整数型，1チャンネル(モノクロ)の画像を格納する配列を作成
    double scale = 4.0;


    // グレースケール画像に変換
    cv::Mat gray;
    cv::cvtColor(*this->SourceFrame_p , gray, CV_BGR2GRAY);
    cv::Mat smallImg(
    		cv::saturate_cast<int>(this->SourceFrame_p->rows/scale),
			cv::saturate_cast<int>(this->SourceFrame_p->cols/scale),
			CV_8UC1);    // 処理時間短縮のために画像を縮小
    cv::resize(gray, smallImg, smallImg.size(), 0, 0, cv::INTER_LINEAR);
    cv::equalizeHist( smallImg, smallImg);

    //std::vector<cv::Rect> detects;
    /// マルチスケール（顔）探索xo
    // 画像，出力矩形，縮小スケール，最低矩形数，（フラグ），最小矩形
    cascade.detectMultiScale(smallImg, this->detects, 1.1, 2, CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
    //cascade.detectMultiScale(smallImg, faces);

    //----------------------------------------------------------------------------
    // 処理時間計測
    this->laptime=clock()-clock_base;
    return 0;
}
cv::Mat *krDetector::drawResult(cv::Mat *SourceFrame_p){
    //scaleの値を用いて元画像を縮小、符号なし8ビット整数型，1チャンネル(モノクロ)の画像を格納する配列を作成
    double scale = 4.0;

    // 結果の描画
	std::vector<cv::Rect>::const_iterator r = this->detects.begin();
	for(; r != this->detects.end(); ++r)
	{
		cv::Point center;
		int radius;

		center.x = cv::saturate_cast<int>((r->x + r->width*0.5)*scale);
		center.y = cv::saturate_cast<int>((r->y + r->height*0.5)*scale);
		radius = cv::saturate_cast<int>((r->width + r->height)*0.25*scale);
		cv::circle( *(this->SourceFrame_p), center, radius, cv::Scalar(80,80,255), 3, 8, 0 );
	}
	  //cv::namedWindow("result", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
      //cv::imshow( "Detector", *img_p );
      //this->frame = *img_p ;
      //cv::waitKey(0);

    return this->SourceFrame_p;

}
std::vector<cv::Rect> *krDetector::getDetects(){
	return &this->detects ;
}

krDetector::~krDetector() {
	// TODO 自動生成されるデストラクターのスタブ
}

} /* namespace korbinian */
