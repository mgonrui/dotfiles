#include <stdio.h>
#include <stdlib.h>
int ft_arr_len(int start, int end, int *sum)
{
    *sum  = 1;
    int i = 0;
    if (start > end)
    {
        *sum = -1;
    }
    while (start != end)
    {
        start += *sum;
        i++;
    }
    return i;
}
int     *ft_range(int start, int end)
{
    int sum = 0;
    int arr_len = ft_arr_len(start, end, &sum);
    int *range = (int *)malloc(sizeof (int) * arr_len);
    int i = 0;

    while (i <= arr_len)
    {
        range[i] = start;
        start += sum;
        i++;
    }
    return range;
}

int main(void)
{
    int start = -11;
    int end = -3;
    int *arr_num = ft_range(start, end);
    int i = 0;
    int sum = 1;
    int arr_len = ft_arr_len(start, end, &sum);
    printf("%d ", arr_len);
    while (i < arr_len);
    {
        printf("%d ", arr_num[0]);
        i++;
    }
    return 0;
}