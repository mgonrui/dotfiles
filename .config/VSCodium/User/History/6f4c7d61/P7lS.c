#include <unistd.h>
void print_digits(d1, d2, d3, d4)
    {
        write(1, &d1, 4);
        write(1, &d2, 4);
        write(1, " ", 1);
        write(1, &d3, 4);
        write(1, &d4, 4);
        write(1, ",", 1);
        write(1, " ", 1);
    }
void ft_print_comb2(void)
{
    char d1 = '0', d2 = '0', d3 = '0', d4 = '0';

    while (d2 <= '8')
    {
        while (d3 <= '9')
        {
            while (d4 <= '9')
            {
                print_digits(d1, d2, d3, d4);
                d4++;
            }
            d4 = d3;
            d3++;
            
        }
        
    }
    

}

int main(void){
    return 0;
}