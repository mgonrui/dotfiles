// #include <stdio.h>

// int main (void){
//     char character;
//     char o;
//     float nwords = 1.0, nchars = 0;
//     printf("enter a sentence: ");
//     while ((character = getchar()) != '\n') {
//         if (character == ' '){
//             nwords++;
//         }
//         else {
//         }
//             nchars++;
//         }
    
//     printf("number of words: %f\n", nwords);
//     printf("number of characters: %f", nchars);
//     return 0;
// }



#include <stdio.h>

int main(void) {
    char character;
    float nwords = 1.0, nchars = 0; // Initialize nchars to 0
    printf("enter a sentence: ");
    while ((character = getchar()) != '\n') {
        if (character == ' ') {
            nwords++;
        } else {
            nchars++; // Increment nchars for each character
        }
    }

    printf("number of words: %.0f\n", nwords); // Use %.0f to print as an integer
    printf("number of characters: %.0f", nchars); // Use %.0f to print as an integer
    return 0;
}
