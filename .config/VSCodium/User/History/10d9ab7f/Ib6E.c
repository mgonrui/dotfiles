#include <stdio.h>
#include <stdlib.h>

int ft_delimeter_found(char c)
{
    if ( c == 32 || c == '\n' || c == '\t' || c == 0)
    {
        return 1;
    }
    return 0;
}

int ft_substrlen (char *str, int *pos)
{
    int substrlen = 0;
    while (ft_delimeter_found(str[*pos]))
    {
        *pos++;
    }
    while (!(ft_delimeter_found(str[*pos])))
    {
        *pos++;
        substrlen++;
    }
    return substrlen;
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_nstrings(char *str)
{
    int i = 0;
    int n = 0;
    while (str[i] != '\0')
    {
        if (!(ft_delimeter_found(str[i])))
        {
            n++;
            while (!(ft_delimeter_found(str[i])))
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return n;
}

// char    **ft_split(char *str)
// {
// }

int main(void)
{
    char *str = "12 123  1 1234 ";
    // char **strs = ft_split(str);
    int i = 0;
    int position = 0;
    int *pos = &position;
    printf("%d\n", ft_substrlen(str, pos));
    printf("%d\n", *pos);
    // char *strs[] = {"hello", "world", "!!!", "..."};
    // while (strs[i])
    // {
    //     printf("%s\n", strs[i]);
    //     i++;
    // }
    

    return 0;
}