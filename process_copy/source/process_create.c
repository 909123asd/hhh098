// source/process_create.c
#include "process_copy.h"

int process_create(const char * srcfile, const char * destfile, int prnum, int blocksize)
{
	    int i;
		pid_t pid;
	    char offset_str[100];
		char block_str[100];
		for(i=0; i<prnum; i++)
		{
			pid = fork();
			if(pid == 0)
	 {
																    	//子进程
																            int offset = i * blocksize;
																			//数字转字符串
			
			sprintf(offset_str,"%d",offset);
			sprintf(block_str,"%d",blocksize);
			//执行外挂Copy程序
																																			            execl("/home/colin/20250915/process/process_copy/MOD/Copy",																																			                    "Copy",	         
	srcfile,
																		 destfile,
																		 offset_str,
																																			  block_str,																																													                    NULL);
																																            //execl只有失败才会走到这里
																																            perror("execl fail");
																			exit(-1);
	}																																																	        else if(pid <0)
																																			 {																	
			perror("fork fail");
																																		            exit(-1);
																																					}
																																			    //父进程继续循环fork
																	 }
     return 0;
}

