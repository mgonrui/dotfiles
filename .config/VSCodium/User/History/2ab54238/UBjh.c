#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n){

    char *count = dest;

    int i = 0;
    while (i++ < n)
    {
        *count = *src;
        count++;
        src++;
        
    }
    // *count = '\0';
    
    return dest;
}

int main(void)
{
    char s1[] = "hello", s2[] = "worldas;dlfkajsdflkjasdl;f";
    printf("%s\n", ft_strcpy(s1, " "));
    printf("%s\n", s1);
    return 0;
}