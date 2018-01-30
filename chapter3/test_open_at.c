/*************************************************************************
	> File Name: test_open_at.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2017 04:10:44 PM CST
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int main()
{
    
    int dir_fd = open("./open",O_RDONLY|O_DIRECTORY);
    if(dir_fd < 0)
    {
        err_sys("Cannot open dir ./open:");
        return 1;
    }
    int fd     = openat(dir_fd,"log.txt", O_RDWR|O_CREAT, 0x640);
    if(fd < 0)
    {
        err_sys("Cannot open file");
        return 1;
    }
}
