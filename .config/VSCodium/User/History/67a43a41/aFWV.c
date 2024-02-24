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
char    **ft_split(char *str)
{
    int nwords = ft_count_words(str);
    char **strs = (char **)malloc(sizeof (char *) * nwords + 1);

}

int main(void)
{
    char *str = "   \t hello world !!!     \n ";
    char **strs = ft_split(str);
    printf("%d\n", ft_count_words(str));
    return 0;
}