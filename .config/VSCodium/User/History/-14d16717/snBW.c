#include <stdio.h>

int ft_str_is_numeric(char *str)
{
    int is_numeric = 1, count = 0;
    while (str[count] != '\0')
    {
        if(str[count] < 48 || str[count] > 57)
        {
                is_numeric = 0;
        }
        count++;
    }
    if(count == 0)
    {
        is_numeric = 0;
    }
    
    return is_numeric ;
}

int main(void)
{
    printf("%d\n", ft_str_is_numeric(""));
    return 0;
}