// #include <stdio.h>

// void ft_sort_int_tab(int *tab, int size)
// {
//     int i, j = 0, largest_pos, largest = tab[0], sorted[size];
//     while (j < size)
//     {
//         i = 0, largest_pos = 0;
//         while (i < size)
//         {
//             // largest = tab[i];
//             if (largest < tab[i])
//             {
//                 largest = tab[i];
//                 largest_pos = i;
//             }
//             i++;
//         }
//         // printf("%d", -j -1);
//         sorted[size -1 -j] = largest;
//         largest = 0;
//         tab[largest_pos] = 0;
//         j++;
//     }
//     j = 0;
//     while (j < size)
//     {
//         tab[j] = sorted[j];
//         j++;
//     }
    
    
//         // printf("%d", sorted[size -1]);
//         // printf("%d", sizeof(sorted) / sizeof(sorted[0]) );
    
// }

// int main(void)
// {
//     int arr[] = {0, 600, 5, 9, 1, -1};
//     ft_sort_int_tab(arr, 6);
//     for (int i = 0; i< 6; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab [i];
				tab[i] = tab [i + 1];
				tab [i + 1] = swap;
			}
			i++;
		}
		size--;
	}
}
int	main()
{
	int tab[6] = {7, 6, 3, -4, 2, 5};
	int size = 6;

	ft_sort_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d, %d", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]); 
	return (0);
}	