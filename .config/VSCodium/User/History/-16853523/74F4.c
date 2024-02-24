#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{

}

int main(void)
{
    char dest[] = "hello";
    char src[] = "world";
    int size = 3;
    printf("%s\n", ft_strlcpy(dest, src, size));
    return 0;
}