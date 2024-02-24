void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdio.h>
int main(void)
{
    int a = 1, b =4;
    ft_swap(a, b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}