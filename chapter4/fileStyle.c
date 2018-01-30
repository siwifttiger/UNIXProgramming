/*************************************************************************
	> File Name: fileStyle.c
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Dec 2017 06:58:09 PM CST
 ************************************************************************/

#include "apue.h"


int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for(i = 1;  i < argc ; ++i)
    {
        printf("%s: ",argv[i]);
        if(lstat(argv[i],&buf) < 0)
        {
            err_sys("lstat error");
        }

        if(S_ISREG(buf.st_mode))
            ptr = "regular";
        else if(S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if(S_ISCHR(buf.st_mode))
            ptr = "character special";
        else if(S_ISBLK(buf.st_mode))
            ptr = "block special";
        else if(S_ISFIFO(buf.st_mode))
            ptr = "FIFO";
        else if(S_ISLNK(buf.st_mode))
            ptr = "symbol link";
        else if(S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "** unknown mode **";
        printf("%s\n",ptr);
    }
    exit(0);
}
