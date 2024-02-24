#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
    
}

void ft_putnbr_base(int nbr, char *base)
{
    // if (nbr < 0)
    // {
    //     ft_putchar('-');
    //     nbr = -nbr;
    // }
    if (nbr < ft_strlen(base))
    {
        ft_putchar(base[nbr]);
    }
    else
    {
        ft_putnbr_base(nbr / ft_strlen(base), base);
        ft_putnbr_base(nbr % ft_strlen(base), base);
    }
}

int main(void)
{
    char* dec = "0123456789";
    char* bin = "01";
    char* hex = "0123456789ABCDEF";
    char* oct = "poniguay";

    ft_putnbr_base(19, bin);
    return 0;
}