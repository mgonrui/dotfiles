#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char    *ft_strrev(char *str)
{
    int end_position = ft_strlen(str) - 1;
    printf("%c\n", str[end_position]);
    return str;
}

int main(void)
{
    char str[] = "1234567";
    ft_strrev(str);
    // printf("%s\n", ft_strrev(str));
    return 0;
}