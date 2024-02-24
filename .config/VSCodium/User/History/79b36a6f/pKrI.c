#include <unistd.h>
#include <stdio.h>


void ft_putnbr(int nb)
{
    int rest;
    while (nb > 9)
    {
        rest += nb % 10;
        nb = nb /10;
    }
    
    printf("%d\n", nb);
    printf("%d\n", rest);
    

}

int main(void)
{
    ft_putnbr(4200);
    return 0;
}