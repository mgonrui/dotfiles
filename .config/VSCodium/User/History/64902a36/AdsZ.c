#include <stdio.h>

int main (void) {
    double  x,
            y = 1,
            sqroot,
            average,
            division;

    printf("enter a positive number: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input. Please enter a valid positive number.\n");
        return 1; // Return a non-zero value to indicate an error.
    }
    // while ( y != division) {
    //     division = x / y;
    //     average = (y + division) / 2;
    //     y = average;
    //     printf("divison %lf\n", division);
    //     printf("average %lf\n", average);
    //     printf("y %lf\n", y );
    //     printf("x %lf\n", x);
    // } 
    return 0;
}