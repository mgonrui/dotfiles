#include <unistd.h>
#include <stdio.h>


void ft_putnbr(int nb)
{
    if (nb > 9)
    {
        ft_putnbr (nb / 10);
        ft_putnbr (nb %10);
    }
    else
    {
        write (1, (nb + 48), 1);
    }
    
    

}

int main(void)
{
    ft_putnbr(4210);
    return 0;
}