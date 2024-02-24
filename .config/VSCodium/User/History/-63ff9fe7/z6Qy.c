#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_print_comb(void)
{
    int d1 = 0, d2 = 0, d3 = 0;
    while (d1 <= 7 && d2 <= 8 && d3 <= 9)
    {
            d3 = d2 + 1;
            while (d3 <= 9)
        {
                ft_putchar(d1 + '0');
                ft_putchar(d2 + '0');
                ft_putchar(d3 + '0');
                ft_putchar('\n');
                d3++;
            }
            d2++;
            
    }
    

}

int main(void)
{
    ft_print_comb();
    return 0;
}