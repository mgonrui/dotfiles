#include <stdio.h>
#include <stdlib.h>

int ft_ndigits(int nbr)
{
    int i = 0;
    int mult = 1;
    while (1)
    {
        if (mult >= nbr)
        {
            return i;
        }
        mult *= 10;
        i++;
    }
    
}

char	*ft_itoa(int nbr)
{
    char *str = malloc(sizeof (int) * 10);
    int i = 0;
    if (nbr < 0)
    {
        str[i++] = '-';
        nbr = -nbr;
    }
    else if (nbr < 9)
    {
        str[i++] = nbr + '0';
    }
    printf("%s\n", str);
    // return str;
}

int main(void)
{
    // char *str = ft_itoa(5);
    // ft_itoa(5);
    printf("%d\n", ft_ndigits(9999999));
    // printf("%s\n", str);
}