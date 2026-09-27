#include "process_copy.h"

int block_cur(const char * srcfile, int prnum)
{
	    struct stat stat_buf;
		stat(srcfile, &stat_buf);
		off_t filesize = stat_buf.st_size;
		off_t blocksize;
		if(filesize % prnum == 0)
		{
			blocksize = filesize / prnum;
											    }
    	else
		{
  																        blocksize = filesize / prnum + 1;
																		    }
																			printf("文件总大小：%lld，每个块大小：%lld\n",(long long)filesize,(long long)blocksize);
																		    return blocksize;
}

