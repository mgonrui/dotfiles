#include <unistd.h>

void print_digits(d1, d2, d3)
    {
        write(1, &d1, 4);
        write(1, &d2, 4);
        write(1, &d3, 4);
        write(1, ",", 1);
        write(1, " ", 1);
    }

void ft_print_comb(void)
{
    char d1 = '0', d2 = '0', d3 = '0';
    int num = 0, calc;
    while (d1 < '7' && d2 < '8' && d3 < '9')
    
}

int main(void){
    ft_print_comb();
    return 0;
}