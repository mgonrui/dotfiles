#include <stdio.h>
#include <ctype.h>


int main(void){
    char message[100];
    int ch, i = 0, j = 0, is_palindrome = 0;
    printf("enter a message: ");
    while((ch = getchar()) != '\n'){
        message[i++] = ch;
    }
    i--;
    printf("i = %d, j = %d\n", i, j);

    while(i > j){
        if (isalpha(message[j])  || isalpha(message[i])){
            if (message[j] != message[i]){
                is_palindrome = 1;
            }
        }
        j++;
        i--;
        printf("i = %d, j = %d\n", i, j);
    }

    if (is_palindrome){
        printf("Not a palindrome\n");
        printf("message: %s\n", message);
    }
    else{
        printf("Palindrome\n");
        printf("message: %s\n", message);
    }
    return 0;
}