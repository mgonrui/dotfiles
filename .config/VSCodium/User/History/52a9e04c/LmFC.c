#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    if (min >= max)
    {
        return NULL;
    }

    int i = 0;
    int *arr = malloc(sizeof (min) * (max - min));
    if (arr == NULL)
    {
        return NULL;
    }
    while (i < (max - min))
    {
        arr[i] = min + i;
        i++;
    }
    return arr;
}

int main(void)
{
    int min = 4, max = 2;
    int i = 0;
    int *arr = ft_range(min, max);
    while (i < (max - min))
    {
        printf("%d ", arr[i++]);
    }
    

    return 0;
}