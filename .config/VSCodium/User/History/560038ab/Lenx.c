void ft_rev_int_tab(int *tab, int size)
{
    int *endtab = tab + size;
    int i = 0;
    return endtab - tab;
    // while (i++ < size)
    // {

    }
}

#include <stdio.h>

int main(void){
    int arr[] = {0, 1, 2, 3, 4, 5};
    printf("%d", ft_rev_int_tab(arr, 6));
}