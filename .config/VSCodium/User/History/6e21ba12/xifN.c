#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 3, b = 9;
    printf("value of a: %d\n", a);
    printf("value of b: %d\n", b);
    ft_swap(&a, &b);
    printf("values swapped succesfully\n");
    printf("value of a: %d\n", a);
    printf("value of b: %d\n", b);
    return 0;
}