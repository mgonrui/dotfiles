#include <stdio.h>
int main (void) {
    long double n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%Lf", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%Lf\n", factorial);
    return 0;
}


// short = 7
// int =  16
// long = 20
// long long =  20
// float = 34
// double =  170
// long double = 