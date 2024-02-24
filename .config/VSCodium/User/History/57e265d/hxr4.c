#include <stdio.h>
#include <stdlib.h>


int ft_digit_found(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int	ft_atoi(const char *str)
{
    int number = 0;
    int i = 0;

    while(ft_digit_found(str[i]))
    {
        number *= 10;
        number += str[i] - '0';
        i++;
    }
    return number;
}

int main(void)
{
    char *number = "\t -345a";
    printf("%d\n",ft_atoi(number));
    printf("%d\n", atoi(number));
    return 0;

}