#include <stdio.h>
#include <stdlib.h>


int	ft_atoi(const char *str)
{
    int number = 0;
    return number;
}

int main(void)
{
    char *str = "\t\n\0 123";
    printf("%d\n", atoi(str));
    // printf("%d\n", ft_atoi(str));
    return 0;
}