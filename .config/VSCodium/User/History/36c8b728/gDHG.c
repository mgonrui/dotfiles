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
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    // char *strjoin = (char *)malloc();
}

int main(void)
{
    char *strs[] = {"hello", "world", "!!!"};
    char *sep = "_-_";
    printf("%d\n", ft_total_length(3, strs, sep));
    // printf("%p\n", strs);
    // printf("%ld", sizeof (strs) / sizeof (char *));
    return 0;
}