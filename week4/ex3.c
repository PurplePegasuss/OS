#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    char c_line[199];

    while(666){
        printf("C:\\> ");
        scanf("%s",c_line);
        system(c_line);
    }

  return 0;
}