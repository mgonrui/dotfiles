#include <stdio.h>

int ft_is_prime(int nb)
{
    int dividend = 2;
    while (dividend < nb)
    {
        if ((nb / dividend) == 0)
        {
            return 0;
        }
        dividend++;
    }
    return 1;
}

int main(void)
{
    printf("%d\n", ft_is_prime(11));
    return 0;
}