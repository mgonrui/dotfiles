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

int ft_error(char *base)
{
    if (ft_strlen(base) <= 1)
    {
        return 1;
    }
    int i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '-')
        {
            return 1;
        }
        // int j = i + 1;
        // while (base[j] != '\0')
        // {
        //     if (base[j] == base[i])
        //     {
        //         return 0;
        //     }
        //     j++;
        // }
        
        i++;
    }
    
}

void ft_putnbr_base(int nbr, char *base)
{
    if (ft_error(base))
    {
        return; 
    }
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
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
    char* error = "234+";

    ft_putnbr_base(-15, hex);
    printf("\n");
    ft_putnbr_base(-15, hex);
    return 0;
}