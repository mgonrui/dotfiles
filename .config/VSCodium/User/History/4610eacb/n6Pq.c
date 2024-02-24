#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *range;

    return range;
}

int main(void)
{
    int range_start = 4, range_end = 10;
    int *range = ft_range(range_start, range_end);
    for (int i = 0; i < (range_end - range_start); i++)
    {
        printf(range[i]);
    }
    return 0;
}