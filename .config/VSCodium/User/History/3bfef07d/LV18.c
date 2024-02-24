#include <stdio.h>
#include <stdlib.h>

int ft_ndigits(int nbr)
{
    int i = 0;
    int mult = 1;
    if (nbr < 0)
    {
        nbr = -nbr;
        i++;
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
    int n_digits = ft_ndigits(nbr);
    char *str = (char *)malloc(sizeof (char) * n_digits + 1);
    str[n_digits--] = '\n';
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    if (nbr == 0)
    {
        str[0] = '0';
        return str;
    }
    while (nbr > 0)
    {
        str[n_digits--] = nbr % 10 + '0';
        nbr /= 10;
    }
        
    return str;
}

int main(void)
{
    char *str = ft_itoa(-525);
    printf("%s", str);
    // printf("%d\n",ft_ndigits(-12345));
}