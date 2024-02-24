#include <stdio.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int count = 0, dest_size = 0;
    char *retdest = dest;
    while (*dest != '\0')
    {
        dest++;
        dest_size++;
    }
    
    while (count++ < (size - dest_size - 1) && *src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest  = '\0';
    return ( count + dest_size);
}

int main(void)
{
    char dest[2] = "123", *src = "45";
    // strlcat(dest, src, 4);
    printf("%d\n", ft_strlcat(dest, src, 0));
    printf("%s\n", dest);
    return 0;
}