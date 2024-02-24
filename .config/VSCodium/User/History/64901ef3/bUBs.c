#include <stdio.h>

int main (void) {

    char character, firstname;
    printf("enter a first and last name: ");
    firstname = getchar();
    while ((character = getchar()) != ' ' );
    // do nothing
    printf("%c", firstname);
    printf("%c", ',');
    printf("%c", ' ');
    while ((character = getchar()) != '\n' ){
        printf("%c", character);
    }
    printf("%c", '.');
    return 0;
}