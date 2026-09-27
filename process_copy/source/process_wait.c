// source/process_wait.c
#include "process_copy.h"

void process_wait(void)
{
	    pid_t zpid;
		int status;
		//循环回收所有子进程，直到wait返回-1（没有子进程）
		while( (zpid = wait(&status)) > 0 )

{
	printf("父进程回收子进程pid=%d\n",zpid);
	}
}

