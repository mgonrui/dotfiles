#include <stdio.h>
#include <unistd.h>

int ft_nonvalid(int number)
{
    if (number < 0)
    {
        return 1;
    }
    return 0;

}
int ft_recursive_factorial(int nb)
{
    int i = 1, factor = 1;
    if (ft_nonvalid(nb))
    {
        return 0;
    }
    while (nb > 0)
    {
        factor *= nb;
        nb--;
        ft_recursive_factorial(nb);
    }
    return factor;
}

int main(void)
{
    printf("%d\n", ft_recursive_factorial(-400));
    return 0;
}