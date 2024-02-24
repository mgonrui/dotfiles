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

void ft_store_numbers(int nbr, int i, char *str)
{
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
        // printf("hello");
        ft_store_numbers(nbr % 10, i, str);
        ft_store_numbers(nbr / 10, i, str);
    }

}

char	*ft_itoa(int nbr)
{
    char *str = (char *)malloc(sizeof (char) * ft_ndigits(nbr) + 1);
    int i = 0;
    ft_store_numbers(nbr, i, str);
    return str;
}

int main(void)
{
    char *str = ft_itoa(3345);
    printf("%s\n", str);
}