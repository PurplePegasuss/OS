#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* realloc_custom(void* p,size_t size){
    if (p == NULL){
        return malloc(size);
    }
    if (size < 0){
        printf("Incorrect size \n");
        return 0;
    }else if (size == 0){
        free(p);
        return 0;
    }else {
        void* p1 = malloc(size);
        memcpy(p1, p, size);

        free(p);

        return p1;
    }
}

int main()
{
    int* intArr;
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);

    intArr = malloc(n * sizeof(int));

    for (int i = 0;i<n;i++){
        intArr[i] = i;
        printf("%d ",intArr[i]);
    }
    printf("\n");
    realloc_custom(intArr, (n + 3)*sizeof(int));

    return 0;
}