/*
Linux system is known to allocate its PID's consequetively(apart from OpenBSD f.e.),
so the values of PID's are rising from one iteration to another. As there is 1 fork,
at each iteration we have a parent and its generated child process (2^1 = 2). Hence,
after repeating this program 10 times we have annotations of 20 processes in the 
format of "parent-child" with consequetively rising number of PID value. 
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int N = 10;
    pid_t pid_f = fork();
    pid_t pid_g = getpid();
    if (pid_f == 0){
        printf("Hello from child [%d-%d]\n", getpid(),N);
    }else if (pid_f != 0){
        printf("Hello from parent [%d-%d]\n", getpid(),N);
    };
    return 0;
}