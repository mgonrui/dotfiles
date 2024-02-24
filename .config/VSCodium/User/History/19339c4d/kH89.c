#include <stdio.h>

int eliminate_spaces_and_calculate_symbol(char *str)
{
    int symbol = 1;
    int i = 0;
    while (!(str[i] >= '0' && str[i] <= '9'))
    {
        if (str[i] = '-')
        {

        }
        i++;
    }
    
    return i;
}
int ft_atoi(char *str)
{
    int number = 0;
    return number;
}

int main(void)
{
    char str[] = "---+--+ 1234ab56";
    // ft_printf(ft_atoi(str));
    printf("%d\n", eliminate_spaces_and_calculate_symbol(str));
    return 0;
}
