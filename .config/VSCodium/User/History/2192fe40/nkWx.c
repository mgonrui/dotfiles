#include <stdio.h>

int ft_find_next_prime(int nb)
{
    while(1)
    {
        int i = 2;
        while (i < nb)
        {
            i++;
            if (!(nb % i))
            {
                break;
            }
            return i;
        }
        
    }
}
int main(void)
{
    printf("%d\n", ft_find_next_prime(8));
    return 0;
}
