/*************************************************************************
    > File Name: spinlock.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 01 Aug 2018 08:47:13 PM PDT
 ************************************************************************/
/*
 * >do what :compare spin_lock with mutex about timecost
*/
#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

static int num = 0;
static pthread_mutex_t mutex;

int get_current_timestamp(){
	struct timeval now = {0, 0};
	gettimeofday(&now,NULL);
	return now.tv_sec * 1000 * 1000 + now.tv_usec;
}

void *thread_proc(void *arg){
	int i = 0;
	int j = 0;
	for (;i < 1000000; ++i){
		pthread_mutex_lock(&mutex);
		for (j = 0; j < 100; ++j){
			//do nothing
			//but make spin_lock cost more time than mutex thread
		}
		++num;
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	pthread_t thread1,thread2;
	pthread_mutex_init(&mutex,NULL);
	int start = get_current_timestamp();
	int ret = -1;
	int end = 0;

	ret = pthread_create(&thread1,NULL,(void *)thread_proc,NULL);
	if (-1 == ret){
		printf("thread1 create fail\n");
	}
	ret = pthread_create(&thread2,NULL,(void *)thread_proc,NULL);
	if (0 != ret){
		printf("thread2 create fail\n");
	}
	ret = pthread_join(thread1,NULL);
	if (0 != ret){	
		printf("thread1 join fail\n");
	}
	ret = pthread_join(thread2,NULL);
	if (0 != ret){	
		printf("thread2 join fail\n");
	}

	printf("num = %d\n",num);
	end = get_current_timestamp();
	printf("cost = %d\n",end - start);
	
	pthread_mutex_destroy(&mutex);
}

