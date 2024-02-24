#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return(len);
    
}


int main(void)
{
    char *str = "";
    printf("%lu\n", strlen(str));
    printf("%d\n", ft_strlen(str));
    return 0;
}