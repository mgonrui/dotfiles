#include <stdio.h>

int main (void){
    int nchar = 0;
    char character;
    char string[nchar];
    printf("enter message: ");
    while ((character = getchar()) != '\n' ){
        string[nchar] = character;
        nchar++;
        printf("%c", string[nchar]);

    }
    return 0;
}