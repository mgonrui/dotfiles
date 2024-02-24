#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_strlen(char* str)
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
    if (nbr <)


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