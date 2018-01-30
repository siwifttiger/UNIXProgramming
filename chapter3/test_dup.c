/*************************************************************************
	> File Name: test_dup.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Dec 2017 10:02:47 AM CST
 ************************************************************************/

#include "apue.h"
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd = open("test_dup.log",O_WRONLY|O_CREAT|O_EXCL,0x777);
    if(fd < 0)
        err_sys("open error");
    dup2(fd,1);
    printf("test dup");
}
