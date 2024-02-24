#include <stdio.h>
int main (void) {
    long n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%ld", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%ld\n", factorial);
    return 0;
}


// short = 7
// int =  16
// long