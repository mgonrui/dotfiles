#include <stdio.h>
int main (void) {
    long long n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%lld", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%lld\n", factorial);
    return 0;
}


// short = 7
// int =  16
// long = 20
// long long = 