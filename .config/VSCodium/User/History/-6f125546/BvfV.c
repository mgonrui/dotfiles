#include <stdio.h>

int main(void){
    char message[] = {}, reversal[] = {};
    int ch, i = 0, j = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        message[i] = ch;
        i++;
    }
    while (i){
        reversal[i--] = message[j++];
    }
    printf("message is: %s \n", message);
    printf("reversal is: %s \n", reversal);
    return 0;
}