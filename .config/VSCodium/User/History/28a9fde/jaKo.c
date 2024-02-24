#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int result = 1, i = 0;
    if (power < 0)
    {
        return 0;
    }
    if (0 == power && 0 == nb)
    {
        return 1;
    }
    while (i++ < power)
    {
        result *= nb;
    }
    return result;
}

int main(void)
{
    printf("%d\n",ft_iterative_power(4, 2));
    return 0;
}