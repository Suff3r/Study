/*************************************************************************
    > File Name: test2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 29 Jul 2018 08:26:45 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("program 1 started\n");
	char *newargv[] = { "hello", "world" };
	char *newenviron[] = { NULL };
	int pid=fork();
	if(pid < 0)
	exit(EXIT_FAILURE);
	if(pid == 0)
	{
		execve("./main2", newargv, newenviron); //打开同级目录下的main2程序
		perror("execve"); /* execve() only returns on error */
		exit(EXIT_FAILURE);
	}

	//父进程继续
	sleep(5); //do something
	printf("Promgram 1 finished!\n");
	return 0;
}

