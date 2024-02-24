#include <stdio.h>

char *ft_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += 1;
        }
        i++;
    }
    
    return str;
}

int main(void)
{
    printf("%s\n", ft_strupcase("Hello World!!!"));
    return 0;
}