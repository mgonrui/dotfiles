#include <stdio.h>

int main (void){
    char character;
    char o;
    float nwords = 1.0, nchars;
    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        if (character == ' '){
            nwords++;
        }
        else {
        }
            nchars++;
        }
    
    printf("number of words: %f\n", nwords);
    printf("number of characters: %f", nchars);
    return 0;
}