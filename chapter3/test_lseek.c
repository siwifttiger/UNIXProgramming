/*************************************************************************
	> File Name: test_lseek.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2017 05:15:06 PM CST
 ************************************************************************/

#include "apue.h"
#include <unistd.h>

int main()
{
    /*测试标准输入能否被设置偏移量*/
    if((lseek(STDIN_FILENO,0,SEEK_SET)) == -1)
    {
        err_sys("Cannot seek");
    }
    else{
        printf("seek ok\n");
    }
}
