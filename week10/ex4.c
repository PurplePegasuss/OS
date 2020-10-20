#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main()
{
    struct dirent *pDirectory;
    struct stat buff;
    DIR  *dirp;
    dirp = opendir("./tmp/");
    int numberOfFiles = 0;

    char *fileNames[20];

    int fileInode[20];
    int i = 0;
    while ((pDirectory = readdir(dirp)) != NULL) {
            stat(pDirectory->d_name,&buff);
            fileNames[i] = pDirectory->d_name;
            fileInode[i] = buff.st_ino;
            i++;
    }
    closedir (dirp);

    int n = i;
    int flag;

    for(int i=0; i < n;i++){    
        flag = 1;

        if (fileInode[i] != -1){
            for (int j = 0;j < n;j++){
                if ((j != i) && (fileInode[i] == fileInode[j])){
                    flag++;
                }
            };
        }

        if (flag>2){
            printf("%d: ",fileInode[i]);
            for (int k = 0;k < n;k++){
                if (fileInode[i] == fileInode[k]){
                    printf(" %s",fileNames[k]);
                }
            };
            printf("\n");
        };

        for (int j = 0;j < n;j++){
            if ((j != i) && (fileInode[i]== fileInode[j])) fileInode[j] = -1;
        };
        fileInode[i] = -1;
    }

    return 0;
}
