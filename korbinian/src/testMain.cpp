//============================================================================
// Name        : korbinian.cpp
// Author      : k.Ishii
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
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
	krBrain brain((char*)"aaa");
	krCamera camera(0);
	krControl c;
	krReportFrame r;
	krMonitor m;
	krKokoe k;
	krDetector d1("/home/katsuya/opencv-3.0.0/data/haarcascades/haarcascade_frontalface_alt.xml");
	krDetector d2("/home/katsuya/opencv-3.0.0/data/haarcascades/haarcascade_smile.xml");

	while(c.DoStep()){
		camera.DoStep();
		r.DoStep(&camera.frame);
		d1.DoStep(&camera.frame);
		d2.DoStep(&camera.frame);
		k.DoStep();

        m.Print(0,1,"Total:%7d msec.",c.getTotaltime());
        k.Print(c.getTotaltime()/3,"%d",c.getTotaltime());
		m.DoStep();
	}
	krArea area(&brain);
	return 0;
}
