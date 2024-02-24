#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
{
    char *retdest = dest;
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
    return retdest; 
}

int main(void)
{
    char dest[1] = "0", *src = "12345";
    // strcat(dest, src);
    ft_strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}