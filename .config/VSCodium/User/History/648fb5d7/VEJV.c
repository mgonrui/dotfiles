# include <stdio.h>

int main (void) {
    int digit, number;
    printf("enter phone number: ");
    while((digit = getchar()) != '\n'){
        printf("%d\n", digit);
    }

    return 0;
}