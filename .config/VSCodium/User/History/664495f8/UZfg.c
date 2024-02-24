#include <stdio.h>

int main (void){
    int nchar = 0;
    char character;
    char string[] = {0};
    printf("enter message: ");
    while ((character = getchar()) != '\n' ){
        string[nchar] = character;
        nchar++;

    }
    return 0;
}