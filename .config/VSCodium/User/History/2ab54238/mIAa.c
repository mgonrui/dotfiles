#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n){


    int i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    // *count = '\0';
    
    return dest;
}

int main(void)
{
    char s1[] = "hello1234", s2[] = "world";
    printf("%s\n", ft_strncpy(s1, s2, sizeof(s1)));
    printf("%s\n", s1);
    return 0;
}