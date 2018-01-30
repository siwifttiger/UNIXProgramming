#include "apue.h"
#define BUFFERSIZE 4096

int main()
{

	int n;
	char buf[BUFFERSIZE] = {0};
	while((n  = read(STDIN_FILENO,buf,BUFFERSIZE)) > 0)
		if(write(STDOUT_FILENO,buf,n) != n)
			err_sys("write error");
	if(n < 0)
		err_sys("read error");
	exit(0);
}
