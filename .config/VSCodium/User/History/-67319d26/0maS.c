#include <unistd.h>
#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
    
}


int main(void)
{
    char dest[] = "hello";
    char src[] = "world";
    ft_strcpy(dest, src);  
    printf("%s\n", src);
    printf("%s\n", dest);
    return 0;
}