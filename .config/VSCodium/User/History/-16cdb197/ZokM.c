#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i = 0;
    char *copy = malloc(sizeof (*src) * (sizeof (src) / sizeof (src[0])));

    while (src[i] != '\0')
    {
        copy[i] = src[i];
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