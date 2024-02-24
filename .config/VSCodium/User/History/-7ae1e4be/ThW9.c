#include <stdio.h>

int num_digits(n){
    int ndigits = 1;
    while (n > 9){
        n /= 10;
        ndigits++;
    }
    return ndigits;
}

int ditit(n,k){
    int digitlist[num_digits(n)];
    for (int i = 0; i < num_digits(n); i++){
        n /= 10;
        digitlist[i] = n % 10;
        printf("%d", digitlist[i]);
    }

}

int main(void){
    // printf("%d", digit(829, 1));
    digit(829, 1);
}
