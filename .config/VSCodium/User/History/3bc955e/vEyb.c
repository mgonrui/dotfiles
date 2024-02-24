#include <unistd.h>
#include <stdio.h>



int     *ft_range(int start, int end)
{
    int arr_len = 0;
    while (start < end)
    {
        start++;
        arr_len++;
    }
    start -= arr_len;

    printf("start: %d\n", start);
    printf("end: %d\n", end);
    printf("arr_len: %d\n", arr_len);

}


int main(void)
{
    ft_range(2, 9);
    return 0;
}