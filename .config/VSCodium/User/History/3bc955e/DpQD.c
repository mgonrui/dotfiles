#include <unistd.h>
#include <stdio.h>



int     *ft_range(int start, int end)
{
    if (start > end)
    {
        int swap = start;
        start = end;
        end = swap;
    }

    int arr_len = 0;
    while (start < end)
    {
        start++;
        arr_len++;
    }
    start -= arr_len;

    printf("start: %d\n", start);
    printf("end: %d\n", end);

}


int main(void)
{
    ft_range(0, -3);
    return 0;
}