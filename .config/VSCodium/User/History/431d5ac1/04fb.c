#include <stdio.h>

int ft_sqrt(int nb)
{
    int i = 1;
    while (i < nb)
    {
        if ((i * i) == nb)
        {
            return i;
        }
        i++;
    }
    return 0; 
}

int main(void)
{
    printf("%d\n",ft_sqrt(400));
    return 0;
}