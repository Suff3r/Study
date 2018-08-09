/*************************************************************************
	> File Name: philo_eat.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Aug 2018 10:05:50 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>

sem_t chopstick[5];
sem_t count;

void *philo_thrd(void* arg){
    int i = (int)arg;
    while(1){
        sem_wait(&count);
        sem_wait(&chopstick[i]);
        sem_wait(&chopstick[(i+1)%5]);
        printf("philosopher %d eat\n",i);
        sleep(1);
        sem_post(&chopstick[i]);
        sem_post(&chopstick[(i+1)%5]);
        printf("philosopher %d think\n",i);
        sleep(1);
        sem_post(&count);
    }
}
int main(){
    int i = 0;
    pthread_t tid[5];
    
    sem_init(&count,0,4);
    for( ; i < 5; ++i){
        sem_init(&chopstick[i],0,1);
    }
    for(i = 0; i < 5; ++i){
        pthread_create(&tid[i],NULL,philo_thrd,(void*)i);
    }
    for(i = 0; i < 5; ++i){
        pthread_join(tid[i],NULL);
    }
    sleep(1);
    
    for( ; i < 5; ++i){
        sem_destroy(&chopstick[i]);
    }

}
