#include <stdio.h>
#include <stdlib.h>
int ft_arr_len(int start, int end)
{
    int sum  = 1;
    int i = 0;
    if (start > end)
    {
        sum = -1;
    }
    while (start != end)
    {
        start += sum;
        i++;
    }
    return i;
}
int     *ft_range(int start, int end)
{

}

int main(void)
{
    int start = -11;
    int end = -3;
    printf("%d\n",ft_arr_len(start, end));
    // int *arr_num = ft_range(start, end);
    // int i = 0;
    // while (arr_num[i] != end)
    // {
    //     printf("%d ", arr_num[i]);
    //     i++;
    // }
    return 0;
}