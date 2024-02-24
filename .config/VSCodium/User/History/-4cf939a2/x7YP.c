#include <stdio.h>

char ft_strupcase(char ch)
{
        if( ch>= 97 && ch<= 122)
        {
            ch -= 32;
        }
    return ch;
}

char ft_strlowercase(char ch)
{
        if( ch >= 65 && ch <= 91)
        {
            ch += 32;
        }
    return ch;
}

char *ft_strcapitalize(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
            str[count] = ft_strlowercase(str[count]);
            count++;
    }
    
    return str;
}

int main(void)
{
    char str[] = "salut, commEnt tu vas ? 42mots quarante-deux; cinquante+et+un";
    printf("%s\n", ft_strcapitalize(str));
    return 0;
}