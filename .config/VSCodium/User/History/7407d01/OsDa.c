#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int result = 0;
    while (nb != 0)
    {
      result = nb *= --nb;
    }
    return result;
}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(4));
    return 0;
}