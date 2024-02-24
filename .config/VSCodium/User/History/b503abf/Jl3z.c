#include <stdio.h>

char *ft_strupcase(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        if( str[count] >= 97 && str[count] <= 122)
        {
            str[count] -= 32;
        }
        count++;
    }
    return str;
}

int main(void)
{
    char str[] = "heLlo-wOrld";
    printf("%s", ft_strupcase(str));
    return 0;
}