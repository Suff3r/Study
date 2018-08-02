/*************************************************************************
    > File Name: main2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 29 Jul 2018 08:28:24 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
printf("program 2 started\n");
int i;
for(i = 0; i<argc;i++)
printf("%s\n",argv[i]);
sleep(5); //do something
printf("Promgram 2 finished!\n");
return 0;
}
