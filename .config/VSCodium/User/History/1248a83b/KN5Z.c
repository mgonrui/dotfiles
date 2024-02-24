#include <stdio.h>

char *ft_strcpy(char *dest, char *src){

    char *count = dest;

    while (*src != '\0')
    {
        *count = *src;
        count++;
        
    }
    
    return *dest;
}

int main(void)
{
    printf("%s", ft_strcpy("hello", "world"));
    return 0;
}