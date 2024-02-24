#include <stdio.h>

char *ft_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
    
    return str;
}

int main(void)
{
    char string[] = "Hello World!!!";
    printf("%s\n", ft_strupcase(string));
    return 0;
}