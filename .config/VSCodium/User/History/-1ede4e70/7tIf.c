int ft_fibonacci(int index)
{
    if (index == 1)
    {
        return 1;
    }
    ft_fibonacci( index * (ft_fibonacci(index -1)));
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_fibonacci(5));
    return 0;
}