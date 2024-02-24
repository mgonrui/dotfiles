#include <stdio.h>
#include <stdlib.h>


char *ft_strcpy(char *src, char *copy)
{
    int i = 0;
    while (src[i] != '\0')
    {
        copy[i] = src[i];
        i++;
    }
    return copy;
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

char *ft_strdup(char *src)
{
    char *copy = (char)malloc(sizeof (src) * ft_strlen(src));
    copy = ft_strcpy(src, copy);
    return copy;
}

int main(void)
{
    char str[] = "hello";
    char* p = ft_strdup(str);
    return 0;
}