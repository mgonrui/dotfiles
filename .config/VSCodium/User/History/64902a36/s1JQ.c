#include <stdio.h>

int main (void) {
    float   x,
            y = 1,
            sqroot,
            average,
            division;

    printf("enter a positive number: ");
    scanf("%f", &x);
    do {
        division = x / y;
        average = (y + division) / 2;
        y = average;
    } while ( y != division);
    return 0;
}