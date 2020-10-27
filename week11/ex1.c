#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fout = open("ex1.txt",O_RDWR);

    char *txt = "This is a nice day\n";

    int size = strlen(txt);
    
    ftruncate(fout,size);

    char *p = mmap(NULL, size, PROT_READ | PROT_WRITE,MAP_SHARED, fout, 0);

    memcpy (p, txt, size);


    munmap(p,size);
    
    close(fout);

    return 0;
}