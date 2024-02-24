#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
{

}

int main(void)
{
    char dest[] = "hello ", *src = "world";
    strcat(dest, src);
    printf("%s\n", dest);
    ft_strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}