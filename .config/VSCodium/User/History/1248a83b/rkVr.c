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
    char s1[] = "hello", s2[] = "wasd;flkajsd;flkjasd;fljorld";
    printf("%s\n", ft_strcpy(s1, s2));
    printf("%s\n", s1);
    return 0;
}