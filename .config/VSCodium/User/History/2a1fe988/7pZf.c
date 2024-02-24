#include <stdio.h>

char *ft_strlowercase(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        if( str[count] >= 65 && str[count] <= 91)
        {
            str[count] += 32;
        }
        count++;
    }
    return str;
}

int main(void)
{
    char str[] = "heLlo-wOrld";
    printf("%s", ft_strlowercase(str));
    return 0;
}