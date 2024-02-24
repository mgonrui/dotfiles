#include <stdio.h>

#define NELEMS(a) (sizeof (a) * sizeof (a[0]))


int main(void)
{
    int *arr = { 1, 2, 3, 4, 5}
    printf("%ld", NELEMS(arr));
    return 0;
}
