#include <unistd.h>

void ft_sort_int_tab(int *tab, int size)
{
    int iterations = 0; 
    while (iterations < (size * size))
    {
        int i = 0;
        int swap = 0;
        while (i < size)
        {
            if (tab[i] > tab[i +1])
            {
                swap = tab[i];
                tab[i] = tab[i +1];
                tab[i + 1] = swap;
            }
            i++;
            iterations++;
        }
        
    }
    

    
}

int main(void)
{
    int arr_size = 7;
    int arr[] = {3, 6, 1, 9, 0, 4, 8};

    return 0;
}