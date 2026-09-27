// source/check_pram.c
#include "process_copy.h"

int check_pram(int argc, const char * srcfile, int prnum)
{
	//1. 判断参数数量
	if(argc <3)
	{
		printf("参数过少！用法：./Process_copy src dest [prnum]\n");
		exit(-1);
		}

//2. 判断源文件是否存在
if(access(srcfile, F_OK) == -1)
														    {
perror("source file not exist");
																		exit(-1);
																		}
													
	//3. 判断进程数量范围
	if(prnum <3 || prnum>100)
{		
	printf("进程数量必须3~100\n");								
																			exit(-1);
																			}
																				return 0;
}

