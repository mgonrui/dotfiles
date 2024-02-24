#include <stdio.h>


int main(void){
    char message[100];
    int ch, i = 0, j = 0, is_palindrome = 0;
    printf("enter a message: ");
    while((ch = getchar()) != '\n'){
        message[i++] = ch;
    }
    i--;

    while(i != j){
        if (message[j] != message[i]){
            is_palindrome = 1;
        }
        j++;
        i--;
    }

    if (is_palindrome){
        printf("Palindrome\n");
        printf("message: %s\n", message);
    }
    else{
        printf("Not a palindrome\n");
        printf("message: %s\n", message);
    }
    return 0;
}