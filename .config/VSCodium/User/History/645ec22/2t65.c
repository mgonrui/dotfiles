#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int i = 0;
    int j = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
int main(void)
{
    char src[] = " world!";
    char dest[20] = "hello";
    int nb = 3;
    printf("%s\n",ft_strncat(dest, src, nb));
    // strncat(dest, src);
    // printf("%s\n", strncat(dest, src));
    // printf("%s\n", dest);
    return 0;
}