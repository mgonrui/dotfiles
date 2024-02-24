#include <stdio.h>

int main (void) {
    double  x,
            y = 1,
            sqroot,
            average,
            division;

    printf("enter a positive number: ");
    scanf("%lf", &x);
    do {
        division = x / y;
        average = (y + division) / 2;
        y = average;
        printf("divison %lf\n", division);
        printf("average %lf\n", average);
        printf("y %lf\n", y );
        printf("x %lf\n", x);
    } while ( y != division);
    return 0;
}