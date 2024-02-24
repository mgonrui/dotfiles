#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    if (min >= max)
    {
        return 0;
    }
    int i = 0;
    int *range = (int *)malloc(sizeof (*range) * (max - min));
    if (range == NULL)
    {
        return NULL;
    }
    while (min < max)
    {
        range[i] = min;
        min++;
        i++;
    }

    return range;
}

int main(void)
{
    int min = 4, max = 4;
    int *range = ft_range(min, max);
    if (range == NULL)
    {
        printf("returned null pointer\n");
        return 0;
    }
    for (int i = 0; i < (max - min); i++)
    {
        printf("%d\n", range[i]);
    }
    return 0;
}