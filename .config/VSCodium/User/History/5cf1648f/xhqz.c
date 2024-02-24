#include <stdio.h>

int ft_fibonacci(int index)
{
    int i = 0, n1 = 0, n2 = 1, temp, result = 0;
    if (index < 0)
    {
        return -1;
    }
    while (i++ < index)
    {
        temp = n2;
        n2 += n1;
        n1 = temp;
    }
    return n2;
    
    
}

int main(void)
{
    printf("%d\n", ft_fibonacci(5));
    return 0;
}