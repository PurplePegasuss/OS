#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <bits/types/__FILE.h>
#include <unistd.h>

int main()
{
    int n = 1024;
    char buffer[n];
    int buf_size = sizeof(buffer);
    memset(buffer,'\0', buf_size);
    int a = setvbuf(stdout, buffer, _IOLBF, n);

    fprintf(stdout,"H");
    sleep(1);

    fprintf(stdout,"e");
    sleep(1);

    fprintf(stdout,"l");
    sleep(1);

    fprintf(stdout,"l");
    sleep(1);

    fprintf(stdout,"o");
    sleep(1);

    fprintf(stdout,"\n");

    return 0;
}