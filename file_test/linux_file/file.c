/*************************************************************************
    > File Name: file.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 05 Aug 2018 10:25:07 PM PDT
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
int main()
{
	int fd,n,i;
	char buff[30] = "hello world!\n";
	char buf[64]  = {0};
	char *path = "./readme.txt";
	//char *path = "./test.txt";

	fd = open(path,O_CREAT|O_RDWR,0x0777);
	assert(fd != -1);
	n = read(fd,buf,30);
	printf("read the content is %s\n",buf);
	i = lseek(fd,10,SEEK_CUR);
	//i = write(fd,buff,strlen(buff));
	n = read(fd,buf,30);
	printf("read the content is %s\n",buf);
	close(fd);
	
	//system("vi test.txt");
	return 0;
}
