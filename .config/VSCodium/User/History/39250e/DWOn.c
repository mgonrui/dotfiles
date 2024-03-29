#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putchar('-');
        ft_putchar(2 + '0');
        ft_putnbr(147483648);
    }

    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        ft_putnbr(nb);
    }
    if (nb <= 9)
    {
        ft_putchar(nb + '0');
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}


int main(void)
{
    ft_putnbr(-2147483648);
    return 0;
}