void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;

}

#include <stdio.h>

int main(void)
{
    int div, mod;
    ft_div_mod(30, 3, &div, &mod);
    printf("div = %d\n", div);
    printf("mod = %d\n", mod);
    return 0;
}