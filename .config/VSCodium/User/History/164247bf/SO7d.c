#include <stdio.h>
#include <stdlib.h>

int ft_ndigits(int nbr)
{
    int i = 1;
    int div = 1;
    while (!(nbr / div <= 9))
    {
        div *= 10;
        i++;
    }
    return i;
}

char	*ft_itoa(int nbr)
{
    int ndigits = ft_ndigits(nbr); 
    char *str = (char *)malloc(sizeof (char) * ndigits + 1);
    ndigits--;
    str[ndigits--] = '\0';
    while (ndigits > 0)
    {
        str[ndigits] = nbr % 10;
        nbr /= 10;
        ndigits--;
    }
    return str;
}

int main(void)
{
    int number = 999990;
    printf("%s", ft_itoa(number));
    // printf("%d\n", ft_ndigits(number));
    return 0;
}
