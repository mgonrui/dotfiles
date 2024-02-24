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
    if(!ft_digit_found(str[0]))
    {
        return 0;
    }
}

int main(void)
{
    char *number = "a345a";
    printf("%d\n",ft_atoi(number));
    printf("%d\n", atoi(number));
    return 0;

}