#include <stdio.h>
void swap(int *x, int *y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
};

int main() {   
    int x, y;
    scanf("%d%d",&x,&y);
    printf("Initial x: %d , initial y: %d\n",x,y);
    swap(&x,&y);
    printf("Swapped x: %d , swapped y: %d\n",x,y);
    }