void ft_ultimate_div_mod(int *a, int *b)
{
    int temp = *a / *b;
    *b = *a % *b;
    *a = temp;
}

#include <stdio.h>

int main(void)
{
    int n1 = 10, n2 = 3;
    int *a = &n1; int* b = &n2;
    ft_ultimate_div_mod(a, b);
    printf("pointer to a: %d\n", *a);
    printf("pointer to b: %d\n", *b);
    return 0;
}