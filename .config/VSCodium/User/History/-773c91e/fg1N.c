#include <stdio.h>
#include <stdlib.h>

int ft_is_delimeter(char c)
{
    if (c == ' ' || c == '\n' || c== '\t')
    {
        return 1;
    }
    return 0;   
}

int ft_nwords(char *str)
{
    int i = 0;
    int nwords = 0;
    while (str[i] != '\0')
    {
        while (ft_is_delimeter(str[i]))
        {
            if (str[i] == '\0')
            {
                break;
            }
            i++;
        }
        if (!(ft_is_delimeter(str[i])) && str[i] != '\0')
        {
            nwords++;
            while (!(ft_is_delimeter(str[i])) && str[i] != '\0')
            {
                i++;
            }
        }
    }
    return nwords;
}

char    **ft_split(char *str)
{
    int nwords = ft_nwords(str);
    char **split = (char **)malloc(sizeof (char *) * nwords + 1);
    char *split[nwords] = NULL;

}

int main(void)
{
    char *string = "  hello world !!!     ";
    char **split = ft_split(string);
    printf("%d\n", ft_nwords(string));
    return 0;
}