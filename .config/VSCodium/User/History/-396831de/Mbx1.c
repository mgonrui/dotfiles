#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    while (*dest != '\0')
    {
        dest++;
    }
        dest++;
    
    int i = 0;
    while (i < (size - 1))
    {
        dest[i] = src [i];
        i++;
    }
    

}

int main(void)
{
    char dest[] = "1";
    char src[] = "12345";
    char* p_dest = dest;
    int size = 3;
    printf("%d\n", ft_strlcat(p_dest, src, size));
    printf("%s\n", dest);
    return 0;
}