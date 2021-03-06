/*
 * krBrain.cpp
 *
 *  Created on: 2015/12/05
 *      Author: katsuya
 */
#include	<iostream>
#include	<string>
#include	"krShm.h"
#include	"krBrain.h"

#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<sys/mman.h>
#include	<cstdlib>

using namespace korbinian;
krBrain::krBrain(char* filename) {
	char	c;
	long	psize;
	int		fd;
	KRBRAIN	*This;

	std::cout << filename ;

	/* マップ用ファイルオープン */
	if((fd=open(filename,O_RDWR|O_CREAT,0666))==-1){perror("open");	exit(-1);}

	/* ページサイズで境界合わせを行なったサイズを計算 */
#ifdef	BSD
	psize=getpagesize();
#else
	psize=sysconf(_SC_PAGE_SIZE);
#endif
	this->size=(sizeof(KRBRAIN)/psize+1)*psize;

	/* ファイルの必要サイズ分先にシークし、0を書き込み */
	/* ファイルのサイズをマップしたいサイズにする為 */
	if(lseek(fd,size,SEEK_SET)<0)		{perror("lseek");	exit(-1);	}
	if(read(fd,&c,sizeof(char))==-1)	{c='\0';}
	if(write(fd,&c,sizeof(char))==-1)	{perror("write");	exit(-1);}

	/* マップ */
	this->sm=(KRBRAIN *)mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if((long)this->sm==-1)				{perror("mmap");	exit(-1);}
	This=this->sm;
	This->fd=fd;

	/* テスト */
	//this->sm.ptr[i].lval=lval;
	/* 実際にファイルに書き込み、同期を取る */
	msync(This,size,0);
}


krBrain::~krBrain() {

	KRBRAIN	*This;
	int fd;

	This=this->sm;
	fd=This->fd;
	/* 実際にファイルに書き込み、同期を取る */
	msync(This,this->size,0);

	/* アンマップ */
	if(munmap(This,size)==-1){
		perror("munmap");
	}

	/* ファイルクローズ */
	close(fd);
}
