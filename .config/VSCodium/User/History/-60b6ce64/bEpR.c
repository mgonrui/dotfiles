#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i = 0, src_size = 0;
    while (src[src_size++] != '\0')
    {
        ; // do nothin'
    }
    while (i < (size ) && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < size)
    {
        dest[i] = '\0';
        i++;
    }

    // return the size of src excluding the null terminator
    return (src_size -1);
}

int main(void)
{
    char s1[] = "h", s2[] = "world";
    printf("%u\n", ft_strlcpy(s1, s2, sizeof(s1)));
    printf("%s\n", s1);
    return 0;
}