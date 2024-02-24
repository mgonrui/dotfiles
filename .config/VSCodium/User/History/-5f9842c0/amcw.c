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
int ft_iterative_factorial(int nb)
{
    int i = 1, factor = 0;
    // if (ft_nonvalid)
    // {
    //     return 0;
    // }
    while (i < nb)
    {
        factor += i * nb;
        i++;
    }
    return factor;
}

int main(void)
{
    printf("%d\n", ft_iterative_factorial(7));
    return 0;
}