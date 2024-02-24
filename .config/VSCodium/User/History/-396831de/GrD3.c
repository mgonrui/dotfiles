#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int j = 0;
    while (dest[j] != '\0')
    {
        j++;
    }
    
    int i = 0;
    while (i < (size -1) && src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    

}

int main(void)
{
    char dest[] = "1";
    char src[] = "2345";
    char* p_dest = dest;
    int size = 4;
    // printf("%d\n", ft_strlcat(p_dest, src, size));
    ft_strlcat(p_dest, src, size);
    printf("%s\n", dest);
    return 0;
}