#include <stdio.h>
int n1,
        n2,
        ln,
        sn,
        dividend,
        divisor;

int gcd (m, n){
    if (n > m){
        ln = n;
        sn = m;
    }
    else {
        ln = m;
        sn = n;
    }
    int denom = ln,
        nomin = sn;
    while (ln % sn != 0) {
        dividend = ln % sn;
        divisor = sn;
        sn = dividend;
        ln = divisor;
    }
    return sn;

};

    
int main(void){
    printf("greatest common divisor: %d \n", gcd(12, 28));
    return 0;
}


