#include <unistd.h>

void	ft_print_numbers(void)
{
    char i = '0';

    while (i <= '9')
    {
        (1==(write(1, &i, 1)));
        i++;
    }
}
int main(void)
{
    ft_print_numbers();
}