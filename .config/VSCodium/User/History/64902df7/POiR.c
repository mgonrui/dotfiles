#include <stdio.h>
int main (void) {
    float n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%f", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%f\n", factorial);
    return 0;
}


// short = 7
// int =  16
// long = 20
// long long =  20