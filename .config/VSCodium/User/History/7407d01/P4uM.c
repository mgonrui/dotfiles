#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int result = 0;
    while (nb != 0)
    {
        nb *= --nb;
    }
    

}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(4));
    return 0;
}