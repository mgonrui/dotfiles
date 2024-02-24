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
    printf("%d\n", ft_is_alphanumeric('\n'));
    return 0;
}