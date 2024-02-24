#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    int factor = 1;
    int i;
    int result;
    while (nb > 1)
    {
        factor *= nb;
        ft_recursive_factorial(--nb);
    }
    return result;
}

int main(void)
{
    printf("%d\n", ft_recursive_factorial(4));
    return 0;
}