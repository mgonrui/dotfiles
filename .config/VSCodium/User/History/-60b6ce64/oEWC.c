#include <stdio.h>
#include <string.h>


unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    int i = 0, src_size = 0;
    // count the size of src
    while (src[src_size++] != '\0')
    {
        ; 
    }
    if (size >= 1)
    {
        // size -1 to leave space for the null terminator on dest
        while (i < (size -1) && src[i] != '\0')
        {
            // copy the source into the destination
            dest[i] = src[i];
            i++;
        }
        // return the size of src excluding the null terminator
    }
    return (src_size -1);
}

int main(void)
{
    char s1[] = "h", s2[] = "world";
    printf("%u\n", ft_strlcpy(s1, s2, 0));
    printf("%s\n", s1);
    // printf("%u\n", strlcpy(s1, s2, 0));
    // printf("%s\n", s1);
    return 0;
}