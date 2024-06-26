#include <stdio.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    return i;
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int len_dest = ft_strlen(dest);
    int len_src = ft_strlen(src);
    int i = len_dest;
    int j = 0;
    while (i < len_dest && src[j] != '\0')
    {
        dest[i] = src[j];
        j++;
        i++;
    }
}

int main(void)
{
    char dest[] = "12";
    char src[] = "345";
    char* p_dest = dest;
    int size = 4;
    // printf("%d\n", ft_strlcat(p_dest, src, size));
    ft_strlcat(p_dest, src, size);
    printf("%s\n", dest);
    return 0;
}