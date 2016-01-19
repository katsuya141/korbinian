/*
 * krBlock.h
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#ifndef KRBLOCK_H_
#define KRBLOCK_H_
#include "opencv2/opencv.hpp"
namespace korbinian {

class krBlock {
public:
	krBlock();
	virtual int doStep();
    int getLaptime();
	virtual ~krBlock();
    
    int laptime;
    std::string name;

};

} /* namespace krbrain */

#endif /* KRBLOCK_H_ */
