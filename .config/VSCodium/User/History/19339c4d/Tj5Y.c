#include <stdio.h>

int eliminate_spaces_and_calculate_symbol(char *str, char *nbr)
{
    int symbol = 1;
    while (!(*str >= '0' && *str <= '9'))
    {
        if (*str == '-')
        {
            symbol *= -1;
        }
        str++;
    }
    nbr = str;
    return symbol;
}
int ft_atoi(char *str)
{
    char* start_of_nbr;
    eliminate_spaces_and_calculate_symbol(str, start_of_nbr);
    printf("%s\n", str);
    printf("%s\n", start_of_nbr);
    int number = 0;
    return number;
}

int main(void)
{
    char str[] = "----- 1234ab56";
    printf("%d",ft_atoi(str));
    // printf("%d\n", eliminate_spaces_and_calculate_symbol(str));
    return 0;
}
