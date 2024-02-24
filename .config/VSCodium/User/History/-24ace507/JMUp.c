#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    int is_alpha = 1, count = 0;
    while (*str != '\0')
    {
            if(*str < 65 || *str > 90)
            {
                if( *str < 97 || *str > 122)
                {
                    is_alpha = 0;
                }
            }
        str++;
    }
    
    return is_alpha;
}

int main(void)
{
    // printf("%d\n", ft_str_is_alpha("ñabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    printf("%d\n", ft_str_is_alpha("asdfasdf"));
    return 0;
}