#include <stdio.h>

int eliminate_spaces_and_calculate_symbol(char* str, int* p_i)
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
    *p_i = i;
    return symbol;
}
int ft_atoi(char *str)
{
    char* start_of_nbr;
    int i = 0;
    int* p_i = &i;
    eliminate_spaces_and_calculate_symbol(str, p_i);
    printf("%s\n", str);
    printf("%d\n", i);
    // printf("%s\n", start_of_nbr);
    int number = 0;
    return number;
}

int main(void)
{
    char str[] = " 1234ab56";
    printf("%d",ft_atoi(str));
    // printf("%d\n", eliminate_spaces_and_calculate_symbol(str));
    return 0;
}
