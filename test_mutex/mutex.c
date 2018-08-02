#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int gn;

void* thread(void *arg)
{
    printf("thread's ID is  %d\n",pthread_self());
    pthread_mutex_lock(&mutex);
    gn = 12;
    printf("Now gn = %d\n",gn);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t id;
    printf("main thread's ID is %d\n",pthread_self());
    gn = 3;
    printf("In main func, gn = %d\n",gn);
    if (!pthread_create(&id, NULL, thread, NULL)) {
        printf("Create thread success!\n");
    } else {
        printf("Create thread failed!\n");
    }
    pthread_join(id, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
