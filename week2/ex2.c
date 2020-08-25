#include <stdio.h>
#include <string.h>
int main() {    
    printf("Enter the string: ");
    char str[1000];
    scanf("%s", str);
    int length = strlen(str);
    for (int i = length - 1; i >= 0 ; --i) {
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}