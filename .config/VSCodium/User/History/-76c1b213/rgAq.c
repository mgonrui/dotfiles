#include <stdio.h>

int ft_str_is_lowercase(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            ;
        }
        else
        {
            return 0;
        }
        str++;
    }
    

}

int main(void)
{
    char *str = "abcd";
    return 0;
}