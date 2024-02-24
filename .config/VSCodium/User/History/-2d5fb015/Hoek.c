void ft_ultimate_div_mod(int *a, int *b)
{
    int temp;
    temp = *a / *b;
    *b = *a % *b;
    *a = temp;

}

#include <stdio.h>

int main(void)
{
    int a = 10, b = 3;
    ft_ultimate_div_mod(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}