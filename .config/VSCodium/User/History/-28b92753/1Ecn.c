#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int i, j = 0, largest = tab[0], sorted[size];
    while (j < size)
    {
        i = 0;
        while (i < size)
        {
            if (largest < tab[i])
            {
                largest = tab[i];
            }
            i++;
        }
        // printf("%d", -j -1);
        sorted[size -1] = largest;
        j++;
        // printf("%d", sorted[size -1]);
    }
    
        // printf("%d", sizeof(sorted) / sizeof(sorted[0]) );
    
}

int main(void)
{
    int arr[] = {10, 5, 9, 1, 70};
    ft_sort_int_tab(arr, 5);
    return 0;
}
