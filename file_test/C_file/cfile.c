/*************************************************************************
    > File Name: cfile.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 06 Aug 2018 12:08:15 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>

int main()
{
	int i = 0;
	char *path = "./readme.txt";
	char buf[30] = "Hi Minho-dodo!\n";
	char buff[30] = {0};
	FILE* fd = fopen(path,"r");
	assert(fd != 0);
#if 0	
	for(; i < strlen(buf); ++i)
	{
		fputc(buf[i], fd);
	}
#endif
	//fwrite(buf,sizeof(char),strlen(buf),fd);
	fread(buff,sizeof(char),30,fd);
	printf("%s",buff);
	fclose(fd);
	//system("cat test.txt");

	return 0;
}
