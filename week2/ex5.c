#include <stdio.h>

void rightsidedSquare(int n){
    for (int i = 1; i <= n; ++i) {
       for (int j = 0; j< (n)/2; ++j){
           printf(" ");
       }
       for (int j = 0; j< (n)/2; ++j){
            printf("*");
       };
     printf("\n");
   };
}

void dotSquare(int n){
    for (int i = 1; i <= n; ++i) {
       for (int j = 0; j< (n); ++j){
           if (j*i % 2 == 0){
               printf("*");
           }else {
               printf(" ");
           }
       }
     printf("\n");
   };
}

void leftsidedSquare(int n){
    for (int i = 1; i <= n; ++i) {
       for (int j = 0; j< (n)/2; ++j){
            printf("*");
       };
     printf("\n");
   };
}

int main(int argc, char *argv[]) {   
    int n = atoi(argv[1]); //argv[1] = pointer to the first command line argument supplied 
    int type;
    printf("Choose needed form:\n 1 - half-row's square with dots\n 2 - right-sided square\n 3 - left-sided square\n");
    scanf("%d",&type);
    switch (type){
        case 1:
            dotSquare(n);
            break;
        case 2:
            rightsidedSquare(n);
            break;
        case 3:
            leftsidedSquare(n);
            break;
        default:
            printf("Wrong number!");
    };
    return 0;
}