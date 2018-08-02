/*************************************************************************
    > File Name: thread_test.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 30 Jul 2018 12:04:30 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thread1_fxn(void* ptr){
	int i = 0;
	for (i; i<5; i++){
		printf("1---------%s %d\n",(char*) ptr,i);
	}
}

void thread2_fxn(void* ptr){
	int i = 0;

	for (i; i<5; i++){
		printf("2---------%s %d\n",(char*) ptr,i);
	}
}

int main(int argc, const char* argv[]){
	pthread_t thread1,thread2;
	char *message1 = "thread1";
	char *message2 = "thread2";

	int ret_thrd1,ret_thrd2;

	int ret_thrd1_join,ret_thrd2_join;
	void* retval;

	ret_thrd1 = pthread_create(&thread1,NULL,(void *)&thread1_fxn,(void *)message1);
	ret_thrd2 = pthread_create(&thread2,NULL,(void *)&thread2_fxn,(void *)message2);
	
	if (ret_thrd1 != 0){
		printf("thread1 creat fail\n");
	}
	if (ret_thrd2 != 0){
		printf("thread2 creat fail\n");
	}

	ret_thrd1_join = pthread_join(thread1, &retval);
	printf("thread1 return status is %d\n",(int)retval);
	printf("thread1 return value is %d\n",ret_thrd1_join);
	if (ret_thrd1_join != 0){
		printf("cannot join with thread1\n");
	}
	printf("thread1 end\n");

	ret_thrd2_join = pthread_join(thread1, &retval);
	printf("thread2 return status is %d\n",(int)retval);
	printf("thread2 return value is %d\n",ret_thrd2_join);
	if (ret_thrd2_join != 0){
		printf("cannot join with thread2\n");
	}
	printf("thread2 end\n");
}

