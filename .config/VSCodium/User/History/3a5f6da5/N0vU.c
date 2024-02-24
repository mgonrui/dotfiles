#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
{

}
int main(void)
{
    char src[] = " world!";
    char dest[20] = "hello";
    // ft_strcat(dest, src);
    strcat(dest, src);
    printf("%s\n", strcat(dest, src));
    printf("%s\n", dest);
    return 0;
}