#include <stdio.h>

int main(void){
    char *message;
    int ch;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        *message = ch;
        message++;
    }
    printf("reversal is %s: ", message);
    return 0;
}