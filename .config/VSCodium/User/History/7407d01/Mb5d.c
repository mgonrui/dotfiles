#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int result = 1;
    int i = 1;
    while (i < nb)
    {
        result *= i++;
    }
    
    return result;
}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(4));
    return 0;
}