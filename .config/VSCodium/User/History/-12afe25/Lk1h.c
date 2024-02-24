#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod  = a % b;
}

int main(void)
{
    int a = 10, b = 3;
    int dividend, module;
    int* div = &dividend; int* mod = &module;
    ft_div_mod(a, b, div, mod);
    printf("div = %d, mod = %d\n", *div, *mod);
    return 0;
}