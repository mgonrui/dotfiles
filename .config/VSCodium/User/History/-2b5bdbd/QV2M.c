#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    int result = 1;
    while (power > 0)
    {
        result *= nb;
        ft_recursive_power(nb, --power);
    }
    return result;
}

int main(void)
{
    printf("%d\n", ft_recursive_power(4, 2));
    return 0;
}