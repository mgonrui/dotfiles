#include <stdio.h>
#include <stdlib.h>

int ft_ndigits(int nbr)
{
    int i = 0;
    int mult = 1;
    if (nbr < 0)
    {
        nbr = -nbr;
    }
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
    char *str = (char *)malloc(sizeof (char) * ft_ndigits(nbr) + 1);
    int i = 0;
    if (nbr < 0)
    {
        str[i++] = '-';
        nbr = -nbr;
    }
    else if (nbr <= 9)
    {
        str[i++] = nbr + '0';
    }
    else if (nbr >= 10)
    {
        ft_itoa(nbr / 10);
        ft_itoa(nbr % 10);
    }
    return str;
}

int main(void)
{
    // char *str = ft_itoa(525);
    // printf("%s\n", str);
    printf("%d\n",ft_ndigits(-12345));
}