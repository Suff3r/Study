#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


struct msg {
    int num;
    struct msg *next;
};

struct msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg){
    struct msg *mp;
    while(1){
        mp = (struct msg*)malloc(sizeof(struct msg));
        mp->num = rand() % 1000 + 1;
        printf("produce %d\n", mp->num);

        pthread_mutex_lock(&lock);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        sleep(2);
    }
}

void *consumer(void *arg){
    while(1){
        pthread_cond_wait(&has_product,&lock);

        struct msg *tmp = head;
        while(tmp != NULL){
            printf("%d ", tmp->num);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main()
{
    pthread_t pid1,pid2;

    pthread_create(&pid1,NULL,producer,NULL);
    pthread_create(&pid2,NULL,consumer,NULL);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);

    pthread_cond_destroy(&has_product);
    pthread_mutex_destroy(&lock);

    return 0;
}


