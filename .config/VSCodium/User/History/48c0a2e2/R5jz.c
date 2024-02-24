#include <stdio.h>
#include <stdlib.h>

int ft_is_delimiter(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    return 0;
}

int ft_is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}


int	ft_atoi(const char *str)
{
    int number = 0;
    int i = 0;
    int sign = 1;
    while (str[i] != '\0')
    {
        while(ft_is_delimiter(str[i]))
        {
            i++;
        }
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        while(ft_is_digit(str[i]))
        {
            number *= 10;
            number += str[i] - '0';
            i++;
        }
    }
    
    return number * sign;
}

int main(void)
{
    char *str = "   +   123";
    printf("%d\n", atoi(str));
    printf("%d\n", ft_atoi(str));
    return 0;
}