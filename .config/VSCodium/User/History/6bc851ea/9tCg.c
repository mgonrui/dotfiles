#include <stdio.h>

int ft_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        str++;
        count++;
    }
    return count;
}


int main(void)
{
    printf("%d\n", ft_strlen("123456"));
    return 0;
}
