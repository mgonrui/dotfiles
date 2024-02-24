#include <stdio.h>

int main (void){
    char character;
    char o;
    int nwords, nchars;
    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        scanf("%c", &o);
        printf("%c%c",character, o);
    
    }

    return 0;
}