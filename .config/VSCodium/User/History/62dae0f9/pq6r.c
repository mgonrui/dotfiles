#include <stdio.h>

int main (void) {

    int number, 
        reversenumber,

    printf("enter a two digit number: ");
    scanf("%3d", &number);

    do {
        reversenumber = number % 10;

    } while (number > 0);

    // firstdigit = number % 10;
    // number = number - firstdigit;
    // seconddigit = number % 100;
    // number = number - seconddigit;
    // thirddigit = number; 

    //reversenumber= firstdigit * 100 + seconddigit * 10 + thirddigit;
    printf("%d\n", reversenumber);
    // printf("%d\n", seconddigit / 10);
    // printf("%d\n", thirddigit / 100);

    // printf("the reversal is: %d\n", reversenumber);
    return 0;
}
