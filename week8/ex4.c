#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
       
int main()
{

    struct rusage tracker;
    int N = 1024*1024*10;
    for (int i = 0;i<20;i++){
        int* intArr;
        intArr = malloc(N);
        memset(intArr, 0,N);
        getrusage(RUSAGE_SELF, &tracker);
        printf("%d\n",tracker.ru_maxrss);
        sleep(1);
    };

    return 0;
}   