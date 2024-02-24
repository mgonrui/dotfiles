#include <stdio.h>

char *ft_strcpy(char *dest, char *src){

    char *count = dest;

    while (*src != '\0')
    {
        *count = *src;
        count++;
        src++;
        
    }
    *count = '\0';
    
    return dest;
}

int main(void)
{
    char s1[] = "hello", s2[] = "world";
    printf("%s", ft_strcpy(s1, " "));
    return 0;
}