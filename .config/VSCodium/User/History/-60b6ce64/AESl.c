#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i = 0;
    while (i < (size -1) && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < size)
    {
        dest[i] = '\0';
        i++;
    }

    return i;
}

int main(void)
{
    char s1[] = "h", s2[] = "world";
    printf("%s\n", ft_strlcpy(s1, s2, sizeof(s1)));
    printf("%s\n", s1);
    return 0;
}