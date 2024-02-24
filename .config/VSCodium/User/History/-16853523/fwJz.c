#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i = 0;
    while (src[i] != '\0')
    {
        while (i < (size -1))
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        i++;
    }
    return i;
}

int main(void)
{
    char dest[] = "hello";
    char src[] = "world";
    int size = 3;
    printf("%s\n", ft_strlcpy(dest, src, size));
    return 0;
}