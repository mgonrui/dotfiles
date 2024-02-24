#include <stdio.h>

int main (void){
    char character;
    float nwords = 1.0, nchars = 0;
    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        if (character == ' '){
            nwords++;
        }
        else {
            nchars++;
        }
    }
    
    printf("number of words: %.0f\n", nwords);
    printf("number of characters: %.0f\n", nchars);
    return 0;
}