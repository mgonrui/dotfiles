# include <stdio.h>

int main (void) {
    int digit, number;
    printf("enter phone number: ");
    while((digit = getchar()) != '\n'){
        if (digit == 'A' || digit == 'B' || digit == 'C'){
            printf("%d", 2);
        }
        else if (digit == 'D' || digit == 'E' || digit == 'F'){
            printf("%d", 3);
        }
        else if (digit == 'G' || digit == 'H' || digit == 'I'){
            printf("%d", 4);
        }
        else if (digit == 'J' || digit == 'K' || digit == 'L'){
            printf("%d", 5);
        }
        else if (digit == 'M' || digit == 'N' || digit == 'O'){
            printf("%d", 6);
        }
        else if (digit == 'P' || digit == 'Q' || digit == 'R'){
            printf("%d", 7);
        }
        else if (digit == 'T' || digit == 'U' || digit == 'V'){
            printf("%d", 8);
        }
        else if (digit == 'W' || digit == 'X' || digit == 'Z'){
            printf("%d", 9);
        }
        else {
            printf("%c", digit);
        printf("\n");
        }
    }

    return 0;
}