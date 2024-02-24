#include <unistd.h>

void ft_putchar(c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
    }

    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
        ft_putnbr(nb);
    }

    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }

    if (nb < 10)
    {
        ft_putchar(nb + '0');
    }

}

int main(void)
{
    ft_putnbr(42);
    return 0;
}