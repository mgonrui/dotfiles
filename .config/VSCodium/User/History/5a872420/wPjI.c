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
void ft_range(int start, int end)
{
    int operator = ft_comparison(start, end);
    int i = start;
    int len = 0;
    while (i != end)
    {
        i += operator;
        len++;
    }
    int *range = (int *)malloc(sizeof (int) * len);
    printf("%d\n", len);
    

}

int main(void)
{
    int start_range= 1;
    int end_range = 6;
    ft_range(start_range, end_range);
    // int *range = ft_range(start_range, end_range);
    // puts(range);
    return 0;
}