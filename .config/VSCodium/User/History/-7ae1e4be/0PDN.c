#include <stdio.h>


int num_digits(n){
    int ndigits = 1;
    while (n > 9){
        n /= 10;
        ndigits++;
    }
    return ndigits;
}
int ditit(int n, int k){
    int digitlist[num_digits(n)];
    for (int i = 0; i < sizeof(digitlist) / sizeof (digitlist[0]); i++){
        n /= 10;
        digitlist[i] = n % 10;
        printf("%d", digitlist[i]);
    }
    return 0;
}

int main(void){
    // printf("%d", digit(829, 1));
    digit(829, 1);
    return 0;
}
