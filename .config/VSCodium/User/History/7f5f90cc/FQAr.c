#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return 0;
    }

    *range = malloc(sizeof (int) * (max -min));
    int i = 0;
    while (i < (max - min))
    {
        *range[max - min + i];
        printf("%d\n",*range[max - min + i]);
        i++;
    }
}

int main(void)
{
    int min  = 4, max = 10;
    int* range;
    ft_ultimate_range(&range, min, max);
    return 0;
}