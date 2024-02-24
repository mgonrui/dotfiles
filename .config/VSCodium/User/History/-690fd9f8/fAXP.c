#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    if (!(str[0] >= '0' && str[0] <= '9' || str[0] == '+' || str[0] == '-'))
    {
        return 0;
    }

    int number;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        number *= 10;
        number += (str[i] - '0');
        printf("%d\n", number);
        i++;
    }

    return number;
}

int main(void)
{
    char *string = "+34";
    // printf("%d\n", atoi(string));
    // printf("%d\n", ft_atoi(string));
    ft_atoi(string);
    return 0;
}