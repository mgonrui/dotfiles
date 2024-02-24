#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int i, j = 0, largest = tab[0], sorted[size];
    while (j < size)
    {
        i = 0; 
        while (i < size)
        {
            // largest = tab[i];
            if (largest < tab[i])
            {
                largest = tab[i];
                tab[i] = 0; //tab[i -1];
            }
            i++;
        }
        // printf("%d", -j -1);
        sorted[size -1 -j] = largest;
        largest = 0;
        j++;
    }
    j = 0;
    while (j < size)
    {
        tab[j] = sorted[j];
        j++;
    }
    
    
        // printf("%d", sorted[size -1]);
        // printf("%d", sizeof(sorted) / sizeof(sorted[0]) );
    
}

int main(void)
{
    int arr[] = {100, 600, 5, 9, 1, 700};
    ft_sort_int_tab(arr, 5);
    for (int i = 0; i< 5; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
