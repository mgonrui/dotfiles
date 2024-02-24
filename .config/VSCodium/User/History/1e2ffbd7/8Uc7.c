#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return 0;
}

int main(void)
{
    char *s1 = "d";
    char *s2 = "a";
    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", ft_strcmp(s1, s2));
    return 0;
}