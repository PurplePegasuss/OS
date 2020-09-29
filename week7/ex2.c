#include <stdio.h>
#include <stdlib.h>

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
    free(intArr);
    return 0;
}