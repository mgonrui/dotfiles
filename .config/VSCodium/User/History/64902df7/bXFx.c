#include <stdio.h>
int main (void) {
    int n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%d", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%d\n", factorial);
    return 0;
}


// short = 7
// int = 