/*************************************************************************
    > File Name: r_w.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 05 Aug 2018 07:24:03 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>


int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_rw;
char *path = "./test.txt";

void rdfile(void* arg){
	int fd;
	char buf[] = "reading...\n";
	//strcat(buf,(char*)arg);
	fd = open(path,O_RDWR|O_APPEND|O_CREAT,0777);
	write(fd,arg,1);
    write(fd,buf,sizeof(buf));
	close(fd);
}
void wtfile(void* arg){
	int fd;
	char buf[] = "writing...\n";
	//strcat(buf,(char*)arg);
	fd = open(path,O_RDWR|O_APPEND|O_CREAT,0777);
    write(fd,arg,1);
	write(fd,buf,sizeof(buf));
	close(fd);
}
void* writer(void* arg){
	sem_wait(&sem_rw);
	printf("Writer %s start writing\n",(char*)arg);
	wtfile(arg);
	sleep(1);
	printf("Writer %s finish writing\n",(char*)arg);
	sem_post(&sem_rw);
}
void* reader(void* arg){
	pthread_mutex_lock(&mutex);
	if (count == 0){
		sem_wait(&sem_rw);
	}
	count++;
	pthread_mutex_unlock(&mutex);
	printf("Reader %s start reading\n",(char*)arg);
    rdfile(arg);
	sleep(1);
	printf("Reader %s finish reading\n",(char*)arg);
	pthread_mutex_lock(&mutex);
	count--;
	if (count == 0){
		sem_post(&sem_rw);
	}
	pthread_mutex_unlock(&mutex);
}
int main(){

	pthread_t id[8];
	sem_init(&sem_rw,0,1);

	pthread_create(&id[0], NULL, reader, (void*)"1");
    pthread_create(&id[1], NULL, reader, (void*)"2");
    pthread_create(&id[2], NULL, writer, (void*)"1");
    pthread_create(&id[3], NULL, writer, (void*)"2");

    pthread_create(&id[4], NULL, reader, (void*)"3");
    pthread_create(&id[5], NULL ,reader, (void*)"4");
    sleep(2);
    pthread_create(&id[6], NULL, reader, (void*)"5");
    pthread_create(&id[7], NULL ,reader, (void*)"6");
    sleep(4);

	pthread_mutex_destroy(&mutex);
	sem_destroy(&sem_rw);

    system("cat ./test.txt");
    return 0;

}

