#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_print_comb(void)
{
    int d1, d2, d3;
    while (d1 <= 7 && d2 <= 8 && d3 <= 9)
    {
            while (d3 <= 9)
            {

                d3++;
            }
            
    }
    

}

int main(void)
{
    ft_print_comb();
    return 0;
}