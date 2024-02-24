#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
    if (!str[0] >= '0' && str[0] <= '9')
    {
        return 0;
    }
    return 1;

}

int main(void)
{
    printf("%d\n", atoi("a23hd"));
    printf("%d\n", ft_atoi("23hd"));
    return 0;
}