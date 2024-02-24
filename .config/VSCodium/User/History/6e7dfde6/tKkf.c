#include <unistd.h>

void ft_print_alphabet(void)
{
    char i = 'z';
    while (i >= 'a')
    {
        write(1, &i, 1);
        i--;
    }
    
}

int main(void){
    ft_print_alphabet();
    return 0;
}