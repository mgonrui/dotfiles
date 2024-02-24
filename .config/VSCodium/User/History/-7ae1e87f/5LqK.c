#include <stdio.h>

int num_digits(n){
    int ndigits = 1;
    while (n > 9){
        n /= 10;
        ndigits++;
    }
    return ndigits;
}

int main(void){
    printf("%d", num_digits(12345));
    return 0; 
}