#include <stdio.h>

int main (void){
    int nvowels = 0;
    char character;

    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        switch (character) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                nvowels++;
                break;
        }
    }
    printf("your sentence has %d vowels \n", nvowels);
    return 0;
}


