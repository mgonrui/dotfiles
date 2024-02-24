int ft_strlen(char *str)
{
    int count = 0;
    while( str[count++] != '\0')
    {
        ;
    }
    return count -1;
}

#include <stdio.h>

int main (void)
{
    char str[] = "1234567";
    printf("%d\n",ft_strlen(str));
    return 0;
}