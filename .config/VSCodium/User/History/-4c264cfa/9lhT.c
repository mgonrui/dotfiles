#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
{
    while (*dest != '\0')
    {
        dest++;
    }
    
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    
}

int main(void)
{
    char dest[5] = "hello ", *src = "world";
    // strcat(dest, src);
    ft_strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}