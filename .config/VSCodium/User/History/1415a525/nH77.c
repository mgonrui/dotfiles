#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    int factor = 1;
    int i;
    int result;
    while (factor <= nb)
    {
        result += factor * (factor +1);
        factor++;
        ft_recursive_factorial(factor);
    }
    return result;
}

int main(void)
{
    printf("%d\n", ft_recursive_factorial(4));
    return 0;
}