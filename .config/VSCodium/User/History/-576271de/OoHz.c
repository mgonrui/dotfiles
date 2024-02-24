#include <unistd.h>

ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_print_comb2(void)
{
    int n1 = 0, n2 = 0;

    while (n1 <= 98)
    {
        n2 = n1 + 1;
        while (n2 <= 99)
        {
            ft_putchar(n1 / 10 + '0');
            ft_putchar(n1 % 10 + '0');
            ft_putchar(" ");
            ft_putchar(n2 / 10 + '0');
            ft_putchar(n2 % 10 + '0');
            ft_putchar(",");
            n2++;
        }
        n1++;
        
    }
    
}

int main(void)
{
    ft_print_comb2();
    return 0;
}