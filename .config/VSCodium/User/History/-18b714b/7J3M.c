#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

int main(void)
{
    int n1 = 1;
    int n2 = 2;
    int *a = &n1;
    int *b = &n2;
    printf("%d\n", n1);
    printf("%d\n", n2);
    ft_swap(*a, *b);
    printf("%d\n", n1);
    printf("%d\n", n2);
    return 0;
}