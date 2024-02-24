#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
    int start_of_string = 0;
    char swap;
    while (start_of_string < size)
    {
        swap = tab[size - 1];
        // printf("%d\n", tab[size -1]);
        tab[size - 1] = tab[start_of_string];
        tab[start_of_string] = swap;
        start_of_string++;
        size--;
    }
    

}

int main(void)
{
    int arr_size = 7;
    int arr_num[7] = {1, 2, 3, 4, 5, 6, 7};
    ft_rev_int_tab( arr_num, arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr_num[i]);
    }
    return 0;
}