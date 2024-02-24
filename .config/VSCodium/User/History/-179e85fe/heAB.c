#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    int result = 1;
    if (power < 0)
    {
        return 0;
    }
    if (0 == power && 0 == nb)
    {
        return 1;
    }
    while (power > 0)
    {
        result *= power--;
        ft_recursive_power(nb, power);
    }
    return result;
}

int main(void)
{
    printf("%d\n",ft_recursive_power(3, 3));
    return 0;
}