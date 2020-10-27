#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    FILE *f = fopen("ex1.txt","r");
    char txt[100];


    while (fgets(txt, 100, f) != NULL){
    }
    
    fclose(f);


    int fout = open("ex4.txt",O_RDWR);

    int size = strlen(txt);

    ftruncate(fout,size);

    char *p = mmap(NULL, size, PROT_READ | PROT_WRITE,MAP_SHARED, fout, 0);

    memcpy (p,txt, size);


    munmap(p,size);
    
    close(fout);
    
    return 0;
}