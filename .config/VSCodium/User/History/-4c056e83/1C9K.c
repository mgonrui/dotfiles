#include <unistd.h>
#include <stdbool.h>

int n1, n2 = '0';

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void ft_write_comb(int n1, int n2){
    ft_putchar(48 + n1 / 10);
    ft_putchar(48 + n1 % 10);
    ft_putchar(' ');
    ft_putchar(48 + n2 / 10);
    ft_putchar(48 + n2 % 10);
}

void ft_print_comb2 (void){
    while (n1 <= 99){
        while (n2 <= 99){
            ft_write_comb(n1, n2);
            n2 ++;
        }
    }
}

int main ()
{
	ft_print_comb2();
} 
