#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){

    *twenties = dollars / 20;
    dollars = dollars % 20;

    *tens= dollars / 10;
    dollars = dollars % 10;

    *fives= dollars / 5;
    dollars = dollars % 5;

    *ones= dollars / 1;
    dollars = dollars % 1;

}

int main(void) {

    int money, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &money);

    pay_amount(money, &twenties, &tens, &fives, &ones);


    return 0;
}