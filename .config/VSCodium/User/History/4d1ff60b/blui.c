#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_error(char* base)
{
    if (ft_strlen(base) <= 1)
    {
        return 1;
    }
    int i = 0;
    while (base[i] != '\0')
    {
        if ( base[i] == '+' || base[i] == '-' || base[i] == ' ')
        {
            return 1;
        }
        int j = i + 1;
        while (base[j] != '\0')
        {
            if (base[j] == base[i])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

int ft_check_char(char c, char* base)
{
    int i = 0;
    while (base[i] != '\0')
    {
        if (c == base[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int ft_atoi_base(char *str, char *base)
{
    if (!ft_check_char(str[0], base))
    {
        return 0;
    }
    int i = 0;
    while (ft_check_char(str[i], base))
    {
        i++;
    }
    return i;
}

int main(void)
{
    char* bin = "01";
    char* oct = "01234567";
    char* hex = "0123456789ABCDEF";
    printf("%d\n", ft_atoi_base("9", oct));
    return 0;
}