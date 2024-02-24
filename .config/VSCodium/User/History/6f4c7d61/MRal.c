#include <unistd.h>

void ft_putchar(c){
    write(1, &c, 1);
}

void print_digits(n1, n2)
    {
        ft_putchar( 1, n1 / 10 + '0', 10);
        ft_putchar( 1, n1 % 10 + '0', 10);
        ft_putchar(1, " ", 4);
        ft_putchar( 1, n2 / 10 + '0', 10);
        ft_putchar( 1, n2 % 10 + '0', 10);
        ft_putchar(1, ",", 10);
        ft_putchar(1, " ", 10);
    }
void ft_print_comb2(void)
{
    int n1 = 0, n2 = 0;
    while (n1 <= 98)
    {
        n2 = n1 + 1;
        while (n2 <= 99)
        {
            print_digits(n1, n2);
            n2++;
        }
        n1++;
        
    }
    
}

int main(void){
    ft_print_comb2();
    return 0;
}