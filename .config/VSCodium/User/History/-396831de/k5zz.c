#include <stdio.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != 0)
    {
        i++;
    }
    return i;
}
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{

}

int main(void)
{
    char dest[] = "12";
    char src[] = "345";
    char* p_dest = dest;
    int size = 4;
    // printf("%d\n", ft_strlcat(p_dest, src, size));
    ft_strlcat(p_dest, src, size);
    printf("%s\n", dest);
    return 0;
}