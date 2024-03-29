#include <stdio.h>

int eliminate_spaces_and_calculate_symbol(char *str)
{
    int symbol = 1;
    int i = 0;
    while (!(str[i] >= '0' && str[i] <= '9'))
    {
        if (str[i] == '-')
        {
            symbol *= -1;
        }
        i++;
    }
    
    return symbol;
}
int ft_atoi(char *str)
{
    int number = 0;
    char c = '3';
    number = c;
    return number;
}

int main(void)
{
    char str[] = "- 1234ab56";
    ft_printf(ft_atoi(str));
    printf("%d\n", eliminate_spaces_and_calculate_symbol(str));
    return 0;
}
