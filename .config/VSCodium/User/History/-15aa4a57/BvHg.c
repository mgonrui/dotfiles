#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ft_putchar (char c)
{
    write(1, &c, 1);
}

int ft_strlen (char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

int ft_error (char *base)
{
    int i = 0, j = 0, coinc = 0;
    while (base[j] != '\0')
    {
        i = 0;
        coinc = 0;
        while (base[i] != '\0')
        {
            if (base[i] == '-' || base[i] == '+')
            {
                return 1;
            }
            if (base[i] == base[j])
            {
                coinc++;
            }
            if (coinc > 1)
            {
                return 1;
            }
            i++;
        }
        j++;
    }
    if (j <= 1)
    {
        return 1;
    }
    return 0;
}



void ft_putnbr_base(int nbr, char *base)
{

    if (ft_error(base))
    {
        return;
    }
    if (nbr < ft_strlen(base))
    {
        ft_putchar(nbr + '0');
    }
}

int main(void)
{
    int nbr = 2;
    char *base[] = { "0123456789", "01", "0123456789ABCDEF", "01234567"};
    ft_putnbr_base(nbr, base[1]);
    // ft_putnbr_base(nbr,"4" );
    return 0;
}