#include <stdio.h>

int ft_str_is_printable(char *str)
{

    
    while (*str != '\0')
    {
        if (!((*str >= 0 && *str <= 31) || (*str == 127)))
        {
            return 0;
        }
        str++;
    }
    return 1;
}
int main(void)
{
    char* str = "\0";
    printf("%d\n",ft_str_is_printable(str));
    return 0;
}