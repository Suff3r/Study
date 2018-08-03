/*************************************************************************
	> File Name: cond_test2.c
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Aug 2018 07:17:46 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int num = 4;
/*释放节点内存*/
static void cleanup_handler(void*arg) {
	printf("Clean up handler of second thread.\n");
	free(arg);
	(void)pthread_mutex_unlock(&mtx);
}
    
static void *producer(void *arg) {
    //pthread_cleanup_push(cleanup_handler,p);
	while(1){
		pthread_mutex_lock(&mtx);
		if (num <= 0){
			for(;num < 4; num++){
				sleep(1);
				printf("Producer works,num = %d\n",num);
			}
		}
		printf("num = %d\n",num);
		pthread_cond_broadcast(&cond);
		printf("It's full,consumer can buy\n");
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
}
static void *consumer(void *arg){
	while(1)
	{
		int randtime = 0;
		randtime = rand()%2 + 1;
		pthread_mutex_lock(&mtx);
		if (num <= 0){
			pthread_cond_wait(&cond,&mtx);//unlock mutex auto
		}
		num--;
		sleep(randtime);
		printf("consumer1 buy,num = %d\n",num);
		pthread_mutex_unlock(&mtx);
	}
}
static void *consumer2(void *arg){
	while(1)
	{
		int randtime = 0;
		randtime = rand()%2 + 1;
		pthread_mutex_lock(&mtx);
		if (num <= 0){
			pthread_cond_wait(&cond,&mtx);//unlock mutex auto
		}
		num--;
		sleep(randtime);
		printf("consumer2 buy,num = %d\n",num);
		pthread_mutex_unlock(&mtx);
	}
}

int main(){
	pthread_t tid1,tid2,tid3;
	pthread_create(&tid1,NULL,producer,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_create(&tid3,NULL,consumer2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);

	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&cond);

	return 0;
}



