//============================================================================
// Name        : korbinian.cpp
// Author      : k.Ishii
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include "krShm.h"
#include "krBrain.h"
#include "krCamera.h"
#include "krControl.h"
#include "krArea.h"
#include "krReportFrame.h"
#include "krMonitor.h"
#include "krKokoe.h"
#include "krDetector.h"
using namespace korbinian;
int main() {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	krControl controler;

	krBrain brain((char*)"aaa");

	krCamera camera(0);
	krReportFrame report0("CameraFrame");

	krDetector detector1(camera.getFrameP(), "/home/katsuya/opencv-3.0.0/data/haarcascades/haarcascade_frontalface_alt.xml");
	krReportFrame report1("Detector1");

	krDetector detector2(camera.getFrameP(),"/home/katsuya/opencv-3.0.0/data/haarcascades/haarcascade_frontalface_alt2.xml");
	krReportFrame report2("Detector2");
	krMonitor monitor;
	krKokoe kokoronokoe;

	while(controler.doStep()){
		camera.doStep();
		report0.doStep(camera.getFrameP());

		detector1.doStep();
		detector2.doStep();
		cv::Mat mat=(*(camera.getFrameP())).clone();
		report1.doStep(detector1.drawResult(&mat));
		report2.doStep(&mat);

        monitor.Print(0,1,"Total:%7d msec.",controler.getTotaltime());
        kokoronokoe.Print(controler.getTotaltime()/3,"%dmsec魂",controler.getTotaltime());

        kokoronokoe.doStep();
		monitor.doStep();
	}
	krArea area(&brain);
	return 0;
}
