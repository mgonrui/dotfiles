#include <stdio.h>
int main (void) {
    short n, factorial = 1;
    printf("enter a positive interger: ");
    scanf("%hd", &n);
    for (int i = 1; i<= n; i++){
        factorial *= i;
    }
    printf("%hd\n", factorial);
    return 0;
}