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
    while (i != end)
    {
        i += operator;
    }
    printf("%d\n", operator);
    

}

int main(void)
{
    int start_range= 2;
    int end_range = -6;
    ft_range(start_range, end_range);
    // int *range = ft_range(start_range, end_range);
    // puts(range);
    return 0;
}