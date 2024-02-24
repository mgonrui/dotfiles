#include <stdio.h>
int main (void) {
    double n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%lf", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%lf\n", factorial);
    return 0;
}


// short = 7
// int =  16
// long = 20
// long long =  20
// float = 34
// double = 