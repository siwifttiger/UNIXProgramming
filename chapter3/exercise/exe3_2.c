/*************************************************************************
	> File Name: exe3_2.c
	> Author: 
	> Mail: 
	> Created Time: Mon 25 Dec 2017 05:48:29 PM CST
 ************************************************************************/

#include "apue.h"
#include <unistd.h>
#include <fcntl.h>

/**************************************
 *实现要点：
 1.需要检测fd的范围，
 2.循环dup，直到打开的fd等于newfd
 3.返回前，关闭已打开的临时fd
 4.注意出错处理
 * ***********************************/

static int my_dup2(int oldfd, int newfd)
{
    int fdarray[newfd];
    int index = 0;

    if(oldfd < 0 || oldfd > 1024) 
    {
        printf("old fd range error\n");
        return -1;
    }

    if(newfd < 0 || newfd > 1024)
    {
        printf("newfd range error\n");
        return -1;
    }
    

    if(oldfd == newfd)
        return newfd;
    
    //先关闭newfd
    close(newfd);
    int newIndexfd;
    for(index = 0; index < newfd; ++index)
    {
        fdarray[index] = dup(oldfd);
        if(newIndexfd == -1)
        {
            err_sys("dup error");
            return -1;
        }
        else
        {
            if(fdarray[index] == newfd)
            {
                newIndexfd = index;
                break;
            }
        }
    }
    //关闭之前打开的fd
    for(index = 0; index < newIndexfd; ++ index)
    {
        close(fdarray[index]);
    }
    return fdarray[newIndexfd];
}


int main()
{
    int fd = open("temp.log",O_RDWR|O_APPEND);
    my_dup2(fd,1);
   // dup2(fd,1);
    printf("my_dup test\n");
}
