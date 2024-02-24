#include <unistd.h>
#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i = 0;
    while (src[i] != '0' && i < n)
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
    int n = 2;
    printf("destination: %s\n", dest);
    ft_strncpy(dest, src, n);
    printf("destination: %s\n", dest);
    return 0;
}