#include <stdio.h>

void bubblesort(int array[],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (n-1)-i;j++){
            if (array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            };
        }
    }
};

int main(){
    int a[50];
    int n;
    printf("Please, enter the size of an array:\n");
    scanf("%d", &n);
    printf("Please, enter the array values (one by one):\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    bubblesort(a,n);
    printf("Resulted array:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}