/*************************************************************************
	> File Name: test_file_hole.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2017 05:21:03 PM CST
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int main()
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;
    if((fd = creat("file.hole",FILE_MODE)) < 0)
        err_sys("creat file error");
    if(write(fd,buf1,10) != 10)
        err_sys("write error");
    
    
    if(lseek(fd,16384,SEEK_SET) == -1)
        err_sys("seek error");
    /*offset now 16384*/

    if(write(fd,buf2,10) != 10)
        err_sys("write error");
    /*offset now 16394*/

    close(fd);
    exit(0);
}
        

