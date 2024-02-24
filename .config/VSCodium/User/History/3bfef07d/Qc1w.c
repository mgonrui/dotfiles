#include <stdio.h>
#include <stdlib.h>

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
    ft_itoa(5);
    // printf("%s\n", str);
}