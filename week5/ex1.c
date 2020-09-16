#include <stdio.h>
#include <pthread.h>

void saySmth(int* threadID){
    printf("Wassup from the thread %d!\n", threadID);
    return 0;
};
/*
We are basically having a 5 creation of threads joining them alltogether,
each thread prints out its ID given through the thread parameter.
*/
int main()
{
    pthread_t threads;

    for(int i = 1; i < 6;i++){
        printf("Thread %d created.\n", i);
        pthread_create(&threads, NULL, saySmth, i);
        pthread_join(threads, NULL);
    }
    pthread_exit(NULL);
    return 0;
}