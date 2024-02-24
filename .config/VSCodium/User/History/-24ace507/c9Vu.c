#include <stdio.h>

int ft_str_is_alpha(char *str)
{
    int is_alpha = 1;
    while (*str != '\0')
    {

        str++;
    }
    
    return is_alpha;
}

int main(void)
{
    // printf("%d\n", ft_str_is_alpha("asdfa"));
    if ('a' == 97){
        printf("a is 97");
    }
    return 0;
}