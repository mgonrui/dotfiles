#include <stdio.h>

int ft_is_prime(int nb)
{
    if (nb == 0 || nb == 1)
    {
        return 0;
    }
    int dividend = 2;
    while (dividend < nb)
    {
        if (!(nb % dividend))
        {
            return 0;
        }
        else
        {
            dividend++;
        }
    }
    return 1;
}

int main(void)
{
    printf("%d\n", ft_is_prime(9));
    return 0;
}