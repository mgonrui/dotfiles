#include <stdio.h>

int main(void){
    char message[] = {};
    int ch, i = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        message[i] = ch;
        i++;
    }
    printf("reversal is: %s \n", message);
    return 0;
}