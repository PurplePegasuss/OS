#include <stdio.h>
#include <stdlib.h>
int main() {
    char **s;
    char foo[] = "Hello World";
    s = malloc(sizeof(char *)); //1st mistake - no memory allocation, we need to use malloc
    *s = foo;
    printf("s is %s\n",*s); // 2nd mistake - we will get dumped garbage if we ask for s, however *s suits our aim.
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
} 