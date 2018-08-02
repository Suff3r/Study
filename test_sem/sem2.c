/*************************************************************************
    > File Name: sem2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 30 Jul 2018 07:13:24 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

void *thread_func(void *msg);
sem_t sem;
sem_t sem1;

#define MSG_SIZE 128

int main(int argc, const char* argv[]){
	int ret = -1;
	char msg[MSG_SIZE];
	pthread_t thread1;
	void *ret_thrd1 = NULL;

	ret = sem_init(&sem,0,0);
	if (ret == -1){
		printf("sem init fail\n");
		exit(EXIT_FAILURE);
	}
	ret = sem_init(&sem1,0,0);
	if (ret != 0){
		printf("sem init fail\n");
		exit(EXIT_FAILURE);
	}

	//creat a thread
	ret = pthread_create(&thread1,NULL,(void *)thread_func,msg);
	if (ret != 0){
		printf("thread creat fail\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Input text, enter 'end' to finish\n");

	sem_wait(&sem1);
	while(strcmp("end\n",msg) != 0){
		fgets(msg,MSG_SIZE,stdin);
		if (strcmp(msg,"test\n") == 0){
			strcpy(msg,"copy_data\n");
			sem_post(&sem);
			sem_wait(&sem1);
		}
		sem_post(&sem);
		sem_wait(&sem1);
	}
	
	//wait the thread finish
	ret = pthread_join(thread1,NULL);
	if (ret == -1){
		printf("thread join fail\n");
		exit(EXIT_FAILURE);
	}

	sem_destroy(&sem);
	sem_destroy(&sem1);
	exit(EXIT_SUCCESS);
}

void* thread_func(void* msg){
	printf("thread1_pend\n");
	sem_post(&sem1);
	sem_wait(&sem);
	char *ptr = msg;

	while(strcmp("end\n",msg) != 0){
		int i = 0;
		for(; ptr[i] != '\0'; i++){
			if(ptr[i] >= 'a' && ptr[i] <= 'z'){
				ptr[i] -= 'a' - 'A'; 
			}
		}
		printf("You input %d characters\n", i-1);
		printf("To Uppercase: %s\n",ptr);
		sem_post(&sem1);
		sem_wait(&sem);
	}
		sem_post(&sem1);
	printf("do nothing but die\n");
	pthread_exit(NULL);
}
