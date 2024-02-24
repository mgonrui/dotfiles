#include <stdio.h>

int ft_iterative_power(int nb, int power){

    int result = 0;
    int i = 0;
    while ( i < power - 1) {
        result *= nb;
        i++;
    }
    return result;
}

int main (void){
    printf("%d\n",ft_iterative_power(3 ,3));
}