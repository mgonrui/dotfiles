#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    int is_alpha = 1, count = 0;
    while (str[count] != '\0')
    {
        if(str[count] < 65 || str[count] > 90)
        {
            is_alpha = 0;
        }
        else if( str[count] < 97 || str[count] > 122)
        {
            is_alpha = 0;
        }
        count++;
    }
    if(count == 0)
    {
        is_alpha = 1;
    }
    
    return is_alpha;
}

int main(void)
{
    printf("%d\n", ft_str_is_alpha("ñabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    // printf("%d\n", ft_str_is_alpha(""));
    return 0;
}