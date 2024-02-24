#include <unistd.h>
#include <stdio.h>



int     *ft_range(int start, int end)
{
    int arr_len = 0;
    int sumsub = 1;
    int new_start = start;
    int new_end = end;
    int *arr_range;

    if (start > end)
    {
        new_start = end;
        new_end = start;
        sumsub = -1;
    }
    while (new_start < new_end)
    {
        new_start ++;
        arr_len++;
    }
    arr_range = (int)malloc(sizeof (int) * arr_len);
    int i = 0;

    while (i < arr_len)
    {
        arr_range[i] = start++;
        i++; 
    }
    
    printf("arr_range: %s\n", arr_range);

    // printf("start: %d\n", start);
    // printf("end: %d\n", end);
    // printf("arr_len: %d\n", arr_len);

}


int main(void)
{
    ft_range(2, -3);
    return 0;
}