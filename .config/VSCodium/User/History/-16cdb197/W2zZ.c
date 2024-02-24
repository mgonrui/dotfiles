#include <stdio.h>
#include <stdlib.h>

int array_size(char *string)
{
    int size = 0;
    while (string[size] != '\0')
    {
        size++;
    }
    return size;
}

char *ft_strdup(char *src)
{
    int i = 0;
    char *copy = (char *)malloc(sizeof (*src) * array_size(src));

    while (src[i] != '\0')
    {
        copy[i] = src[i];
        i++;
    }
    return copy;
}

int main(void)
{

    char *str1 = "hello world";
    char *str2 = ft_strdup(str1);
    printf("%s\n", str2);
    return 0;
}