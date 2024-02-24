#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    if (!(str[0] >= '0' && str[0] <= '9'))
    {
        return 0;
    }
    int number;

}

int main(void)
{
    char *string = "--34";
    printf("%d\n", atoi(string));
    printf("%d\n", ft_atoi(string));
    return 0;
}