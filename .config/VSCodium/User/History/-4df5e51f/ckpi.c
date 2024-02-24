#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){


}

int main(void) {

int money, twenties, tens, fives, ones;

printf("Enter a dollar amount: ");
scanf("%d", &money);

pay_amount(money, &twenties, &tens, &fives, &ones);


    return 0;
}