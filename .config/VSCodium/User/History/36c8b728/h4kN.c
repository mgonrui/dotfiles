#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_total_length (int size, char **strs, char *sep)
{
    int i = 0;
    int total_length = 0;
    while (i < size)
    {
        total_length += ft_strlen(strs[i]);
        total_length += ft_strlen(sep);
        i++;
    }
    total_length -= ft_strlen(sep);
    return total_length + 1;
}

char *ft_strjoin(int size, char **strs, char *sep)
{

    if (size == 0)
    {
        return ((char *)malloc(sizeof (char)));
    }

    int total_length = ft_total_length(size, strs, sep);
    char *strjoin = (char *)malloc(total_length * sizeof(char));
    char *p_strjoin = strjoin;
    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (strs[i][j] != '\0')
        {
            *strjoin = strs[i][j];
            strjoin++;
            j++;
        }
        j = 0;
        while (sep[j] != '\0' && i < (size -1))
        {
            *strjoin = sep[j];
            strjoin++;
            j++;
        }
        
        i++;
        
    }
    return p_strjoin;
    
}

int main(void)
{
    char *strs[] = {"hello", "world", "!!!!"};
    char *sep = "%20";
    printf("%s\n", ft_strjoin(3, strs, sep));
    // printf("%d\n", ft_total_length(3, strs, sep));
    // printf("%p\n", strs);
    // printf("%ld", sizeof (strs) / sizeof (char *));
    return 0;
}