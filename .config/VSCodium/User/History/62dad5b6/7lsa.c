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
      while (ln % sn != 0) {
        if (sn != 0 && ln != 0) {
            dividend = ln % sn;
            divisor = sn;
            sn = dividend;
            ln = divisor;
            //printf("largest: %d, smallest: %d \n", ln, sn);
        }

    }
    gcd = sn;
    printf("greatest common divisor: %d \n", gcd);
    return 0;
}
