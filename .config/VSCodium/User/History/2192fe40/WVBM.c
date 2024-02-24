#include <stdio.h>

int ft_find_next_prime(int nb)
{
    while(1)
    {
        int i = 2;
        int not_prime = 0;
        while (i < nb)
        {
            if (nb % i == 0)
            {
                not_prime = 1;
            }
            i++;
        }
        if (!not_prime)
        {
            return nb;
        }
        nb++;
        
    }
}
int main(void)
{
    printf("%d\n", ft_find_next_prime(8));
    return 0;
}
