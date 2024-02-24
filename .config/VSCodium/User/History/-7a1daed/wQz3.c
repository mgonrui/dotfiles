#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int count = 0;
    while (count < n)
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        count++;
    }
        return 0;
}

int main(void)
{
    char *s1 = "ca", *s2 = "c";
    printf("%d\n", strncmp(s1, s2, 4));
    printf("%d\n", ft_strncmp(s1, s2, 4));
    return 0;
}