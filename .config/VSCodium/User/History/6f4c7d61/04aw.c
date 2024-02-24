#include <unistd.h>

void ft_putchar(c){
    write(1, &c, 1);
}

void print_digits(n1, n2)
    {
        ft_putchar( 1, n1 + '0', 1);
        ft_putchar(1, " ", 1);
        ft_putchar( 1, n2 + '0', 1);
        ft_putchar(1, ",", 1);
        ft_putchar(1, " ", 1);
    }
void ft_print_comb2(void)
{
    int n1 = 0, n2 = 0;

}

int main(void){
    ft_print_comb2();
    return 0;
}