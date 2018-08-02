/*************************************************************************
    > File Name: 1.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 23 Jul 2018 06:30:09 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include "1.h"
void echoRN(void)
{
    int i;
    //srand((int) time(0));
    //srand((int) getpid());
	
    for(i=0;i< 10;i++)
    {
        printf(" %d ", rand()%8);
    }
    printf("\n");
}
