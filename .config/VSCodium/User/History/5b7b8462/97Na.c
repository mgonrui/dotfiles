#include <stdio.h>

int ft_sqrt(int nb)
{
    int i = 0;
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
    printf("%d\n", ft_sqrt(64));
    return 0;
}