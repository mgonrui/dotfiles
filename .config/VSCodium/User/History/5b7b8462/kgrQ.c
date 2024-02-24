#include <stdio.h>

int ft_sqrt(int nb)
{
    int i = 0;
    if (nb == 1)
    {
        return 1;
    }
    while (i < nb)
    {
        if ((i * i) == nb)
        {
            return i;
        }
        i++;
        
    }
    return 0;
}

int main(void)
{
    printf("%d\n", ft_sqrt(25));
    printf("%d\n", ft_sqrt(-10));
    return 0;
}