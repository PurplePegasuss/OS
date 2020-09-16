#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define N 8
int c_sleep_Flag;
int p_sleep_Flag;
long long int iteration;
int buff[N];
int count;

void *producer(void* arg){
    for (;;){
        clock_t begin = clock();
        if (p_sleep_Flag)
            continue;
        else{
            if (count == N){
                p_sleep_Flag = 1;
                c_sleep_Flag = 0;
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Iteration number %lld Time spent on execution of producer (in seconds) : %1.9f\n",iteration++,time_spent);
            }else{
                buff[count]=1;
                count++;
            };
        };
    };
    pthread_exit(NULL);
    return 0;
}

void *consumer(void* arg){
    for (;;){
        clock_t begin = clock();
        if (c_sleep_Flag)
            continue;
        else{
            if (count == 0){
                c_sleep_Flag = 1;
                p_sleep_Flag = 0;
                clock_t end = clock();
                double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("Time spent on execution of consumer (in seconds) : %1.9f\n",time_spent);
            }else{
                buff[count]=0;
                count--;
            };
        };
    };
    pthread_exit(NULL);
    return 0;
}

/*
Comments section:
This is a representation of a producer-consumer problem. 
On my device it takes approximately 268900 iterations of the producer to face race condition, and assuming the fact that
average producer time of each cycle is ~0.000001 seconds, average consumer time of each cycle is ~0.000002
 we can get that:
268900(times)*0.000001(s) + 268900(times)*0.000002(s) =  0.8 secs. 
Remark: this time includes only processes of consumer & producer, all other processes are not included. 
*/

int main()
{
    for (int i = 0; i < N; i++){
        buff[i] = 0;
    }
    p_sleep_Flag = 0;
    c_sleep_Flag = 1;

    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);
    for (;;);
    return 0;
}

