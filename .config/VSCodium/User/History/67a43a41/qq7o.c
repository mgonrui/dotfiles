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
        int j = position;
        int k = 0;
        strs[i] = (char *)malloc(sizeof(char) * ft_word_size(str, &position));
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
    char *str = "hello world ???";
    char **strs = ft_split(str);
    for (int i = 0; i < ft_count_words(str); i++)
    {
        printf("%s\n", strs[i]);
    }
    return 0;
}