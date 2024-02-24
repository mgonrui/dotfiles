#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int size = 0; 
    char *p_str = str;
    while (*p_str != '\0')
    {
        p_str++;
        size++;
    }
    return size;
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int count = 0, dest_size = 0, size_to_return = (ft_strlen(dest) + ft_strlen(src));
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
    return (size_to_return);
}

int main(void)
{
    char dest[20] = "123", *src = "4";
    // strlcat(dest, src, 4);
    printf("%d\n", ft_strlcat(dest, src, 5));
    printf("%s\n", dest);
    return 0;
}