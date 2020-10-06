#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    int N = 1024*1024*10;
    for (int i = 0;i<20;i++){
        int* intArr;
        intArr = malloc(N);
        memset(intArr, 0,N);
        sleep(1);
    };

    return 0;
}
/*

After launching 2 parallel commands I've got the following results:

[1] 32941
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 3  0      0 4030828 169600 6882144    0    0    24    72   19  221  8  4 87  1  0
 1  1      0 4018072 169616 6884088    0    0     0    88 15019 16123 11  7 81  1  0
 2  0      0 4008112 169616 6884108    0    0     0     0 15047 16058  9  7 84  0  0
 0  0      0 3991680 169616 6885160    0    0     0     0 15203 20773  7  4 89  0  0
 4  0      0 3980072 169616 6885684    0    0     0     0 15084 18246  6  3 91  0  0
 1  0      0 3972288 169616 6884196    0    0     0     0 15063 16637  5  3 92  0  0
 0  0      0 3964356 169624 6884196    0    0     0    76 15145 16366 10  7 83  1  0

It's clear to see that the amount of free memory is decreasing with each instantenous iteration, 
the buffered memory increases. The first report is different, as it shows us the average results
before the vmstate command.
*/