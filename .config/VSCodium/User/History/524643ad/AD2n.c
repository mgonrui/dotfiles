#include <stdio.h>

int ft_is_prime(int nb)
{
    int i = 0, dividends_count = 0;
    if (nb == 1 || nb == 0)
    {
        return 0;
    }
    while (i < nb)
    {
        if ((nb % i) != 0)
        {
            dividends_count++;
        }
        i++;
    }
    if (dividends_count > 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    
}

int main(void)
{
    printf("%d\n", ft_is_prime(1));
    printf("%d\n", ft_is_prime(10));
    printf("%d\n", ft_is_prime(11));
    printf("%d\n", ft_is_prime(17));
    return 0;
}