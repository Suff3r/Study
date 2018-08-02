#include <stdio.h>  
#include <signal.h>  
#include <sys/time.h>  

#include "1.h"
static struct itimerval new_value;
void setTimer(void){
    new_value.it_interval.tv_sec = 0; 
    new_value.it_interval.tv_usec = 0;  
    setitimer(ITIMER_REAL, &new_value, NULL);  
}

void signalHandler(int signo)  
{  
    switch (signo){  
        case SIGALRM:
            echoRN();
			//setTimer();
            break;
   }  
}

int main(int argc, char *argv[])  
{  
    signal(SIGALRM, signalHandler);
#if 1
    //struct itimerval new_value;  
    new_value.it_value.tv_sec = 2;  
    new_value.it_value.tv_usec = 0;  
    new_value.it_interval.tv_sec = 1; 
    new_value.it_interval.tv_usec = 0;  
    setitimer(ITIMER_REAL, &new_value, NULL);  
#endif
    while(1);
    return 0;  
}
