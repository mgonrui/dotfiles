#include <stdio.h>

int ft_is_alphanumeric(char c)
{
    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int ft_is_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char ft_convert_to_uppercase(char c)
{
    if (ft_is_uppercase(c))
    {
        return (c - 32);
    }
}

char *ft_strcapitalize(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return str;
}

int main(void)
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    // printf("%s",ft_strcapitalize(str));
    printf("%d\n", ft_convert_to_uppercase('a'));
    return 0;
}