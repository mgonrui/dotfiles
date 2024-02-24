#include <stdio.h>


int main(void){
    char message[100];
    int ch, i = 0;
    printf("enter a message: ");
    while((ch = getchar()) != '\n'){
        message[i] = ch;
    }
    printf("Palindrome\n");
    printf("Not a palindrome\n");
    printf("message: %s\n", message);
    return 0;
}