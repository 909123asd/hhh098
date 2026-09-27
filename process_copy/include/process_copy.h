#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

int check_pram(int argc,const char *srcfile,int prnum);
int block_cur(const char *srcfile,int prnum);
int process_create(const char * srcfile,const char *destfile,int prnum,
                   int blocksize);
void process_wait(void);

