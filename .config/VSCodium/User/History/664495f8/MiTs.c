#include <stdio.h>
#include <ctype.h>

int main (void){
    int nchar = 0;
    char character;
    char string[nchar +1];
    printf("enter message: ");
    while ((character = getchar()) != '\n' ){
        string[nchar] = character;
        nchar++;

    }
    for (int i = 0; i < nchar; i++){
        string[i] = toupper(string[i]);
        // printf("%c", string[i]);
        switch (string[i]) {
            case 'A':
            string[i] = '4';
            break;
            case 'B':
            string[i] = '8';
            break;
            case 'E':
            string[i] = '3';
            break;
            case 'I':
            string[i] = '1';
            break;
            case 'O':
            string[i] = '0';
            break;
            case 'S':
            string[i] = '5';
            break;
        }
        printf("%c", string[i]);
    }
    return 0;
}