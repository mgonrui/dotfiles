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
    int start_position = 0;
    while (start_position < end_position)
    {
        char swap = str[start_position];
        str[start_position] = str[end_position];
        str[end_position] = swap;
        start_position++;
        end_position++;
    }
    
    return str;
}

int main(void)
{
    char str[] = "1234567";
    // ft_strrev(str);
    printf("%s\n", ft_strrev(str));
    return 0;
}