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
    char* str = 0;
    // printf("%d\n",ft_str_is_printable(str));
    printf("%d", ft_str_is_printable("ABDELKFSCO?I340990%"));
    printf("\n%d", ft_str_is_printable("\n\t\v\f"));
    return 0;
}