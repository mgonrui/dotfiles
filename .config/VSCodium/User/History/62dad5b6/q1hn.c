#include <stdio.h>

int main (void){

    int n1,
        n2,
        ln,
        sn,
        remainder,
        dividend,
        divisor,
        gcd;
    printf("enter twho intergers: ");
    scanf("%d %d", &n1, &n2 );
    if (n1 > n2){
        ln = n1;
        sn = n2;
    }
    else {
        ln = n2;
        sn = n1;
    }
    int denom = sn,
        nomin = ln;

      while (ln % sn != 0) {
            dividend = ln % sn;
            divisor = sn;
            sn = dividend;
            ln = divisor;
            //printf("largest: %d, smallest: %d \n", ln, sn);
    }
    gcd = sn;
    denom = denom / gcd;
    nomin = nomin / gcd;
    printf("greatest common divisor: %d \n", gcd);
    printf("fraction to lowest terms: %d/%d \n", nomin, denom);
    return 0;
}
