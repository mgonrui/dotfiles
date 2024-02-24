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
            case 'B':
            string[i] = '8';
            case 'E':
            string[i] = '3';
            case 'I':
            string[i] = '1';
            case 'O':
            string[i] = '0';
            case 'S':
            string[i] = '5';
        }
    }
    return 0;
}