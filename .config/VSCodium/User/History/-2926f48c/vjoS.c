#include <stdio.h>
#include<string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' || *s2 !='\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
        return 0;
}

int main(void)
{
    char *st1 = "ca", *st2 = "cab";
    printf("%d\n", strcmp(st1, st2));
    printf("%d\n", ft_strcmp(st1, st2));
    return 0;
}