#include <stdio.h>
#include <stdlib.h>

int ft_comparison(int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int *ft_range(int start, int end)
{
    int operator = ft_comparison(start, end);
    int i = start;
    int len = 1;
    while (i != end)
    {
        i += operator;
        len++;
    }
    int *range = (int *)malloc(sizeof (int) * len);
    // printf("%d\n", len);
    i = 0;
    while (i < len)
    {
        range[i] = start;
        start+= operator;
        i++;
    }
    return range;
}

int main(void)
{
    int start_range= 1;
    int end_range = 6;
    ft_range(start_range, end_range);
    int range[] = ft_range(start_range, end_range);
    int i =0;
    puts(range);
    // while (range[i])
    // {
    //     printf("%d, ", range[i++]);
    // }
    
    return 0;
}