#include <stdio.h>

int ft_str_is_uppercase(char *str)
{
    while (*str != '\0')
    {
        if (!(*str >= 'A' && *str <= 'Z'))
        {
            return 0;
        }
        str++;
    }
    return 1;
    

}

int main(void)
{
    printf("%d\n", ft_str_is_uppercase(""));
    return 0;
}