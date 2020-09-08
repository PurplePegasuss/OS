#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char c_line[199];

    while(666){
        printf("C:\\> ");
        fgets(c_line, 199, stdin);
        system(c_line);
    }

  return 0;
}