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
        (*pos)++;
    }
    while (!(ft_delimeter_found(str[*pos])))
    {
        (*pos)++;
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

int ft_n_substrings(char *str)
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

char    **ft_split(char *str)
{
    int i = 0;
    int n_substrings = ft_n_substrings(str);
    char **split = (char **)malloc(sizeof (char *) * n_substrings + 1);
    int position_for_malloc = 0;
    while (i < n_substrings)
    {
        split[i] = (char *)malloc(sizeof (char) * ft_substrlen(str, &position_for_malloc));
        i++;
    }
    i = 0;
    int j = 0;
    int k = 0;
    while (str[j] != '\0')
    {
        k = 0;
        while(!(ft_delimeter_found(str[j])))
        {
            if (str[j] == '\0')
            {
                return split;
            }
            split[i][k] = str[j];
            j++;
            k++;

        }
        while(ft_delimeter_found(str[j]))
        {
            if (str[j] == '\0')
            {
                return split;
            }
            j++;
        }
        i++;
    }
    return split;
}

int main(void)
{
    char *str = "hello world !";
    char **strs = ft_split(str);
    int i = 0;
    // int position = 3;
    // printf("%d\n", ft_substrlen(str, &position));
    // printf("%d\n", position);
    // char *strs[] = {"hello", "world", "!!!", "..."};
    while (strs[i])
    {
        printf("%s\n", strs[i]);
        i++;
    }
    

    return 0;
}