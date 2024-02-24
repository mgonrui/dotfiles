#include <stdio.h>
#include <ctype.h>


int main (void) {
    char letter;
    int value = 0;
    printf("enter phone number: ");
    while((letter = toupper(getchar())) != '\n'){
        switch (letter) {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
            value++;
            break;
            case 'D': case 'G':
            value += 2;
            break;
            case 'B': case 'C': case 'M': case 'P':
            value += 3;
            break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
            value += 4;
            case 'K':
            value += 5;
            case 'J': case 'X':
            value += 8;
            case 'Q': case 'Z':
            value += 10;
        }
    }
    printf("Scrabble value: %d\n", value);
    return 0;
}