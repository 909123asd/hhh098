// MOD/Copy.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	    int sfd, dfd;
	    int offset = atoi(argv[3]);
        int blocksize = atoi(argv[4]);
	    int ret;
	  char buf[4096]; //缓冲区，一次读4k
     
	          //打开源文件
	 sfd = open(argv[1],O_RDONLY);
	    if(sfd == -1){
      perror("open src fail");
		      exit(-1);
    }
		    //打开目标文件
	   dfd = open(argv[2],O_WRONLY|O_CREAT,0664);

    if(dfd == -1){                                                          
																			        perror("open dest fail");											         exit(-1);																  }
																			 //跳到自己负责的起始偏移
																			 lseek(sfd, offset, SEEK_SET);
																			 lseek(dfd, offset, SEEK_SET);
int total = 0; //已经拷贝字节计数					    					    //循环读写，直到拷贝完blocksize
while(total < blocksize){																															        ret = read(sfd, buf, sizeof(buf));																													        if(ret <=0) break;
																																					        write(dfd, buf, ret);													        total += ret;
	}																																						    close(sfd);
	  close(dfd);
				 printf("子进程 %d 完成片段拷贝，offset:%d size:%d\n",getpid(),offset,blocksize);																   return 0;
}

