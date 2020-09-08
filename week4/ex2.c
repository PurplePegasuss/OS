/*
By adding fork, a new process is generated for all existing ones, Child process is almost identical 
to the parent generating process. After each iteration the amount of forks doubles,
hence we have simple formula:  2^n = amount of processes, where n is amount of forks.
Therefore in the first case we will have  2^3 = 8 processes, and 2^5 = 32 processes in the second one.

Resulting process trees
1st case: 
 ─ex2─┬─ex2─┬─ex2───ex2
            │     └─ex2
            ├─ex2───ex2
            └─ex2

2nd case:
─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2
     ├─ex2─┬─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2
     ├─ex2─┬─ex2───ex2
     │     └─ex2
     ├─ex2───ex2
     └─ex2
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    for (int i = 0; i< 5; i++) {
        fork();
    };
    sleep(5);
    return 0;
} 