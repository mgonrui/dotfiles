#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }

    *range = malloc(sizeof (int) * (max - min));

    while (i < (max - min))
    {
        *range[min + i] = i;
        i++;
    }
    return i;
}

int main(void)
{
    int min = 4, max = 20, i = 0;
    int *range;
    printf("%d\n", ft_ultimate_range(&range, min, max));
    while (i < (max - min))
    {
        printf("%d ", range[i]);
        i++;
    }
    
    return 0;
}