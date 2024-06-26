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

int ft_is_alphanumeric(char ch)
{
    if  (((ch >= 65 && ch <= 91) ||
        (ch >= 97 && ch <= 122) ||
        (ch >= 48 && ch <= 57)))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

char *ft_strcapitalize(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        if (ft_is_alphanumeric(str[count]))
        {
                // str[count] = ft_strlowercase(str[count]);
            str[count] = ft_strupcase(str[count]);
            count++;

            while(ft_is_alphanumeric(str[count]))
            {
                str[count] = ft_strlowercase(str[count]);
                count++;
            }
        }
        else
        {
            ;
        }
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