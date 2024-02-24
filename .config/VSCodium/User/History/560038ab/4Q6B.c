#include <stdio.h>
void ft_rev_int_tab(int *tab, int size)
{
    int i = 0, swap;
    while (i < (size / 2))
    {
        swap = tab[i];
        tab[i] = tab[size -i -1];
        tab[size -i -1] = swap;
        i++;

    }
}

// #include <stdio.h>

int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5};
    // printf("%d", ft_rev_int_tab(arr, 6));
    ft_rev_int_tab(arr, 6);
    for (int j = 0; j < 6; j++)
    {
        printf("%d", arr[j]);
    }
}