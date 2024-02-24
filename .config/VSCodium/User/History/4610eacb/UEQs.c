#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *range = (int *)malloc(sizeof (range) * (max - min));
    while (min < max)
    {
        *range = min;
        min++;
        range++;
    }

    return range;
}

int main(void)
{
    int min = 4, max = 10;
    int *range = ft_range(min, max);
    for (int i = 0; i < (min - max); i++)
    {
        printf("%d\n", range[i]);
    }
    return 0;
}