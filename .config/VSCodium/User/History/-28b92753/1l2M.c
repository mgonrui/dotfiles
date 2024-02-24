#include <stdio.h>

void ft_sort_int_tab(int *tab, int size)
{
    int i = 0, largest = tab[0], sorted[size -1];
    while (i < size)
    {
        if (largest < tab[i])
        {
            largest = tab[i];
        }
        i++;
    }
    sorted[size -1] = largest;
    printf("%d", sorted[size -1]);
    
    
}

int main(void)
{
    int arr[] = {10, 5, 9, 1, 70};
    ft_sort_int_tab(arr, 5);
    return 0;
}
