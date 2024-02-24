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

int ft_word_len(char *str, int *position)
{
    int len = 0;
    while (ft_is_delimeter(str[*position]))
    {
        (*position)++;
    }
    while (!(ft_is_delimeter(str[*position]))&& str[*position] != '\0')
    {
        len++;
        (*position)++;
    }
    return len;
}

char    **ft_split(char *str)
{
    int nwords = ft_nwords(str);
    char **split = (char **)malloc(sizeof (char *) * nwords + 1);
    // split[nwords] = NULL;
    int i = 0;
    int position = 0;
    while (i < nwords)
    {
        int word_len = ft_word_len(str, &position);
        split[i] = (char)malloc(sizeof (char) * (word_len  + 1));
        int j = 0;
        while (j < word_len)
        {
            split[i][j] = str[position - word_len + j];
            j++;
        }
        
        i++;
    }
    

    return split;

}

int main(void)
{
    char *string = "  1234 1 123   ";
    char **split = ft_split(string);
    // printf("%d\n", ft_nwords(string));
    return 0;
}