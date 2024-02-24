int ft_find_next_prime(int nb)
{
    int next_prime, is_prime = 5, i = 2;

    while (is_prime != 0) 
    {
        is_prime = 0;
        while (i < nb)
        {
            if ((nb % i) == 0){
                is_prime++;
            }
            i++;
            
        }
        if(is_prime != 0)
        {
            nb++;
        }
    }
    return nb;
}


#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_find_next_prime(4));
    return 0;
}