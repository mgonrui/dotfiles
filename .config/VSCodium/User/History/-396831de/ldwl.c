#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int j = 0;
    while (dest[j] != '\0')
    {
        j++;
    }
    int dest_size = j;
    
    int i = 0;
    while (i + dest_size < (size -1) && src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    if (src[i] = '\0')
    {
        return (i + dest_size);
    }
    else
    {
        return (dest_size + i + dest_size);
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