// #include <stdio.h>

// int main(void){
//     char message[100] = {}; 
//     int ch, i = 0, j = 0;
//     printf("Enter a message: ");
//     while ((ch = getchar()) != '\n'){
//         message[i] = ch;
//         i++;
//     }
//     message[i + 1] = '\n';
//     char reversal[i + 1];
//     while (i >= 0){
//         reversal[j] = message[i];
//         j++;
//         i--;
//     }
//     printf("message is: %s \n", message);
//     printf("reversal is: %s \n", reversal);
//     return 0;
// }
#include <stdio.h>

int main(void) {
    char message[100];  // Assuming a maximum message length of 99 characters
    int ch, i = 0, j = 0;

    printf("Enter a message: ");
    
    // Read characters until a newline is encountered
    while ((ch = getchar()) != '\n' && i < sizeof(message) - 1) {
        message[i] = ch;
        i++;
    }

    message[i] = '\0';  // Null-terminate the string

    char reversal[i + 1];  // Add 1 for the null-terminator
    
    // Reverse the message
    i--;  // Move i to the last valid index
    while (i >= 0) {
        reversal[j] = message[i];
        j++;
        i--;
    }

    reversal[j] = '\0';  // Null-terminate the reversed string

    printf("Original message is: %s\n", message);
    printf("Reversal is: %s\n", reversal);

    return 0;
}
