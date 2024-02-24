#include <stdio.h>

int ft_is_prime(int nb)
{
    int dividend = 2;
    while (dividend <= nb)
    {
        if ((nb / dividend) == 0)
        {
            return 0;
        }
        else
        {
            printf("%d\n", dividend);
            dividend++;
        }
    }
    return 10;
}

int main(void)
{
    printf("%d\n", ft_is_prime(10));
    return 0;
}