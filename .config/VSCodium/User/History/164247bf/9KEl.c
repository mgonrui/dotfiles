#include <stdio.h>
#include <stdlib.h>

int ft_ndigits(int nbr)
{
    int i = 1;
    int div = 1;
    while (!(nbr % div <= 9))
    {
        div *= 10;
        i++;
    }
    return i;
}
// char	*ft_itoa(int nbr)
// {

// }

int main(void)
{
    int number = 347;
    // printf("%s", ft_itoa(number));
    printf("%d\n", ft_ndigits(number));
    return 0;
}
