#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
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
    return dest;
}
int main(void)
{
    char src[] = " world!";
    char dest[20] = "hello";
    printf("%s\n",ft_strcat(dest, src));
    // strcat(dest, src);
    // printf("%s\n", strcat(dest, src));
    // printf("%s\n", dest);
    return 0;
}