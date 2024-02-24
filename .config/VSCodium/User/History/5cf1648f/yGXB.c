#include <stdio.h>

int ft_fibonacci(int index)
{
    int i = 0, n1 = 0, n2 = 1, temp, result = 0;
    if (index < 0)
    {
        return -1;
    }
    if (1 == index)
    {
        return 1;
    }
    return (ft_fibonacci(index -1) + ft_fibonacci(index -2));
}

int main(void)
{
    printf("%d\n", ft_fibonacci(5));
    return 0;
}