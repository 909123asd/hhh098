// source/main.c
#include "process_copy.h"
int main(int argc, char** argv)
{
	    int prnum;
		int blocksize;

	    // 判断是否传入进程数量参数
		if (argv[3] == NULL)
		{
			prnum = 3; // 没传，默认3个进程
			}
			
			else  
													 {								  prnum = atoi(argv[3]);
			}

																		    // 参数校验
																			    check_pram(argc, argv[1], prnum);

																			 // 计算每个进程拷贝块大小（分片）
																			    blocksize = block_cur(argv[1], prnum);

																		    // 创建prnum个子进程
																			process_create(argv[1], argv[2], prnum, blocksize);

																		    // 循环回收所有子进程
																			 process_wait();
																		    return 0;
}
