#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char    *ft_strrev(char *str)
{
    int end_pos = ft_strlen(str) - 1;
    int start_pos = 0;
    char swap;
    while (start_pos < end_pos)
    {
        swap = str[start_pos];
        str[start_pos] = str[end_pos];
        str[end_pos] = swap;
        start_pos++;
        end_pos--;
    }
    return str;
}

int main(void)
{
    char str[] = "hello world!!!";
    printf("%s\n", ft_strrev(str));
    return 0;
}