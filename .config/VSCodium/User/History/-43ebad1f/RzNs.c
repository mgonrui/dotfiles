#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int count = 0;
    char *retdest = dest;
    while (*dest != '\0')
    {
        dest++;
    }
    
    while (count++ < nb)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest  = '\0';
    return retdest; 
}

int main(void)
{
    char dest[1] = "0", *src = "12345";
    // strncat(dest, src);
    ft_strncat(dest, src, 3);
    printf("%s\n", dest);
    return 0;
}