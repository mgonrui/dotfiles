#include <stdio.h>

int main(void){
    char *message; 
    int ch, i = 0, j = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        *message = ch;
        message++;
    }

    char reversal[i + 1];

    while (i >= 0){
        reversal[j] = message[i - 1];
        j++;
        i--;
    }
    printf("message is: %s \n", message);
    printf("reversal is: %s \n", reversal);
    return 0;
}