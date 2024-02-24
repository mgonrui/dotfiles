#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len + 1] != '\0')
    {
        len++;
    }
    
}


int main(void)
{
    char *str = "";
    printf("%lu\n", strlen(str));
    return 0;
}