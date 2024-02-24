#include <stdio.h>

int ft_find_next_prime(int nb)
{
    while (1)
    {
        int i = 1, dividends_count = 0;
        while (i < nb)
        {
            if ((nb % i) == 0)
            {
                dividends_count++;
            }
            i++;
        }
        if (dividends_count <= 1)
        {
            return nb;
        }
        else
        nb++;
    }
}

int main(void)
{
    printf("%d\n", ft_find_next_prime(24));
    return 0;
}