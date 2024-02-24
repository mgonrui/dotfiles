#include <stdio.h>

int main (void){
    char character;
    char o;
    int nwords, nchars;
    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        if (character == ' '){
            nwords++;
        }
        else {
        }
            nchars++;
        }
    
    printf("number of words: %d", nwords);
    printf("number of characters: %d", nchars);
    return 0;
}