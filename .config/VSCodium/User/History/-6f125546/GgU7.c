#include <stdio.h>

int main(void){
    char message[100], *p_message = message; 
    int ch, i = 0, j = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n'){
        *p_message = ch;
        p_message++;
    }
    *p_message = '\0';

    char *reversal;

    // while (i >= 0){
    //     reversal[j] = message[i - 1];
    //     j++;
    //     i--;
    // }
    printf("original is: %s \n", message);
    printf("reversal is: %s \n", reversal);
    return 0;
}