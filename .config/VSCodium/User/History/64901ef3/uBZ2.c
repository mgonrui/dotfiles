#include <stdio.h>

int main (void) {

    char character, firstname;
    printf("enter a first and last name: ");
    firstname = getchar();
    while ((character = getchar()) != ' ' ){
        printf("%c", firstname);
        printf("%c", ',');
        printf("%c", ' ');
    }
    while ((character = getchar()) != '\n' ){
        printf("%c", character);
    }



    return 0;
}