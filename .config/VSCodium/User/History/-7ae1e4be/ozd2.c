#include <stdio.h>


int num_digits(int n){
    int ndigits = 1;
    while (n > 9){
        n /= 10;
        ndigits++;
    }
    return ndigits;
}
int digit(int n, int k){
    int digitlist[num_digits(n)];
    for (int i = 0; i < sizeof(digitlist) / sizeof (digitlist[0]); i++){
        digitlist[i] = n % 10;
        n /= 10;
    }
    return digitlist[k - 1];
}

int main(void){
    // printf("%d", digit(829, 1));
    digit(829, 1);
    return 0;
}
