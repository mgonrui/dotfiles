#include <stdio.h>

char *ft_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    
    return str;
}

int main(void)
{
    char string[] = "Hello World!!!";
    printf("%s\n", ft_strlowcase(string));
    return 0;
}