#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    while (*dest != '\0')
    {
        dest++;
    }
    
    int i = 0;
    while (i < (size - 1) && src[i + 2] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    

}

int main(void)
{
    char dest[] = "1";
    char src[] = "2345";
    char* p_dest = dest;
    int size = 7;
    // printf("%d\n", ft_strlcat(p_dest, src, size));
    ft_strlcat(p_dest, src, size);
    printf("%s\n", dest);
    return 0;
}