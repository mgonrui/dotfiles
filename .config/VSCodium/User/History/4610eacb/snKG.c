#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    if (min >= max)
    {
        return NULL;
    }
    int i = 0;
    int *range = (int *)malloc(sizeof (*range) * (max - min));
    if (range == NULL)
    {
        return 0;
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
    int min = 4, max = 1;
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