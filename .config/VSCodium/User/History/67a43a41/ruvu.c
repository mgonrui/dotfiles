#include <stdio.h>
#include <stdlib.h>


// it does not include start/end of string
int ft_delimiter_found(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
    {
        return 1;
    }
    return 0;
}

int ft_count_words(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if(!ft_delimiter_found(str[i]))
        {
            count++;
            while (!ft_delimiter_found(str[i]))
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return count;
}

int ft_word_size(char *str, int *position)
{
    int size = 0;
    while (ft_delimiter_found(str[*position]))
    {
        (*position)++;
    }
    while (!(ft_delimiter_found(str[*position])))
    {
        (*position)++;
        size++;
    }
    return size;
}

char    **ft_split(char *str)
{
    int nwords = ft_count_words(str);
    char **strs = (char **)malloc(sizeof (char *) * nwords + 1);
    int i = 0;
    int position = 0;
    while (i < nwords)
    {
        strs[i] = (char *)malloc(sizeof(char) * ft_word_size(str, &position));
        int j = position;
        int k = 0;
        while (ft_delimiter_found(str[j]))
        {
            j++;
        }
        while (!(ft_delimiter_found(str[j])))
        {
            strs[i][k] = str[j];
            k++;
            j++;
        }
        i++;
    }
    strs[i] = NULL;
    return strs;
}

int main(void)
{
    char *str = "     \t12345    \n 1 123  \t1234";
    char **strs = ft_split(str);
    // printf("%d\n", ft_count_words(str));
    int position = 0;
    // printf("%d\n", ft_word_size(str, &position));
    return 0;
}