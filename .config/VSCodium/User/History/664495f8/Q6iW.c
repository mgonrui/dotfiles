#include <stdio.h>
#include <ctype.h>

int main (void){
    int nchar = 0;
    char character;
    char string[nchar +1];
    printf("enter message: ");
    while ((character = getchar()) != '\n' ){
        string[nchar] = character;
        printf("%c", string[nchar]);
        nchar++;

    }
    for (int i = 0; i < nchar; i++){
        string[i] = toupper(string[i]);
        printf("%c", string[i]);
        // if (string[i] == )
    }
    return 0;
}