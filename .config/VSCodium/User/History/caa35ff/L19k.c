
#include <stdio.h>
int ft_find_next_prime(int nb)
{
    int next_prime, is_prime = 5, i;

    while (1) 
    {
        is_prime = 0;
        i = 2;
        while (i < nb)
        {
            if ((nb % i) == 0){
                is_prime++;
                // printf("is prime: %d\n", is_prime);
            }
            i++;
            
        // printf("is prime: %d\n", is_prime);
        }
        if(is_prime != 0)
        {
            nb++;
        }
        if (is_prime == 0)
        {
            return nb;
        } 
    }
    // printf("is prime: %d\n", is_prime);
}



int main(void)
{
    printf("%d\n", ft_find_next_prime(8));
    return 0;
}