/*************************************************************************
    > File Name: prod_cons.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 03 Aug 2018 12:21:11 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define _SIZE_ 3

int ringbuf[_SIZE_] = {0};

sem_t blanks;//blank
sem_t goods;

void* thread_producer(void* arg)
{
    int i = 0;
    while(1)
    {
        sleep(1);
        sem_wait(&blanks);//生产者申请格子资源
        int data = rand()%10000;
        ringbuf[i] = data;
        printf("Producer sell : %d\n",data);
        i++;
        i %= _SIZE_;
        sem_post(&goods);//每生产一个商品就需要对商品信号量+1
    }
}

//消费者
void* thread_consumer(void* arg)
{
    int i = _SIZE_-1;
    while(1)
    {
        sleep(1);
        sem_wait(&goods); //消费者申请商品资源
        printf("Consumer get : %d\n",ringbuf[i]);
        i++;
        i %= _SIZE_; 
        sem_post(&blanks);//每买走一个商品，就多了一个格子资源。
    }
}

int main()
{

    //将格子信号量初始化为64，将商品信号量初始化为0，以保证生产者优先。
    sem_init(&blanks,0,_SIZE_);
    sem_init(&goods,0,0);

    pthread_t producer;
    pthread_t consumer;
    pthread_create(&producer,NULL,thread_producer,NULL);
    pthread_create(&consumer,NULL,thread_consumer,NULL);
    pthread_join(producer,NULL);
    pthread_join(consumer,NULL);

    sem_destroy(&blanks);
    sem_destroy(&goods);
    return 0;
}

