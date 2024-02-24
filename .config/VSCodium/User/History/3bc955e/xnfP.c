#include <unistd.h>
#include <stdio.h>


int sum_or_sub(int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    return 1;
}

int     *ft_range(int start, int end)
{
    int arr_len = 0;
    int sumsub = sum_or_sub(start, end);
    printf("sumsub: %d\n", sumbub);
    while (start < (end * sumsub))
    {
        start += sumsub;
        arr_len++;
    }
    start -= arr_len;

    printf("start: %d\n", start);
    printf("end: %d\n", end);
    printf("arr_len: %d\n", arr_len);

}


int main(void)
{
    ft_range(2, -3);
    return 0;
}