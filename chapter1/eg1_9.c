/*************************************************************************
	> File Name: simpleShell.c
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2017 07:34:21 PM CST
 ************************************************************************/

#include "apue.h"
#include <sys/wait.h>

static void sig_cal(int signum)
{
    printf("catch signal:%d\n",signum);
    printf("interrupt \n%%");
}

int main()
{
    char buf[MAXLINE];    //from apue.h 
    pid_t pid;
    int status;
    if(signal(SIGINT,sig_cal) == SIG_ERR)
        err_sys("signal error");
    printf("%% ");
    while(fgets(buf,MAXLINE,stdin)!=NULL)
    {
        if(buf[strlen(buf)-1] == '\n')
        {
            buf[strlen(buf)-1] = 0;     //replace newline with NULL
        }
        if((pid = fork()) < 0)
            err_sys("fork error");
        else if(pid == 0)
        {
            /*child */
            execlp(buf,buf,(char *)0);
            err_ret("Couldn't execute: %s",buf);
            exit(127);
        }
        if ((pid = waitpid(pid,&status,0)) < 0)
            err_sys("waitpid error");
        printf("%% ");

    }
    exit(0);
}
