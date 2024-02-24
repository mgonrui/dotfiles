#include <stdio.h>
int n1,
        n2,
        ln,
        sn,
        remainder,
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
    // gcd = sn;
    // denom = denom / gcd;
    // nomin = nomin / gcd;

};

    
int main(void){
    printf("greatest common divisor: %d \n", gcd(4, 8));
    return 0;
}


