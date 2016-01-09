/*
 * krShm.h
 *
 *  Created on: 2015/12/06
 *      Author: katsuya
 */

#ifndef KRSHM_H_
#define KRSHM_H_

#define KRAREA_SIZE (256)

typedef struct{
	int		id;
	char	name[128];
	double	dval;
}KRAREA;

typedef struct{
	char	dataformat[512];
	char	formatversion[512];
	KRAREA	area[KRAREA_SIZE];
	int	fd;
}KRBRAIN;

#endif /* KRSHM_H_ */
