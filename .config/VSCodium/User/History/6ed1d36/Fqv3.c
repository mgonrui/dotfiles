#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

int main(void)
{
    char s1[] = "hello ";
    char s2[] = "worlddddddddddddd";
    printf("%s\n", ft_strcpy(s1, s2));
    // printf("%s\n", strcpy(s1, s2));
    printf("%s\n", s1);
    printf("%s\n", s2);
}