#include <unistd.h>

void ft_print_comb(void)
{
    int num = 0, d1, d2, d3;
    while (d1 < 7 && d2 < 8 && d3 < 9)
    {
        num++;
        d1++;
        // d1 = num / 100;
        // d2 = ((num / 100) / 10);
        // d3 = (((num / 100) % 10));
        if(d1 < d2 < d3)
        {
            write(1, &d1, 1);
            write(1, &d2, 1);
            write(1, &d3, 1);
            write(1, ",", 1);
            write(1, " ", 1);
        }
    }
    
}

int main(void){
    ft_print_comb();
    return 0;
}