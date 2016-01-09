/*
 * krBlock.h
 *
 *  Created on: 2015/12/30
 *      Author: katsuya
 */

#ifndef KRBLOCK_H_
#define KRBLOCK_H_

namespace korbinian {

class krBlock {
public:
	krBlock();
	virtual int DoStep();
    int getLaptime();
	virtual ~krBlock();
    
    int laptime;
};

} /* namespace krbrain */

#endif /* KRBLOCK_H_ */
