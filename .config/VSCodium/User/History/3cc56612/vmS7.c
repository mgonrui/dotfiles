#include <stdio.h>

#define NELEMS(a) (sizeof (a) * sizeof (a[0]))


int main(void)
{
    printf("%d", NELEMS("hello"));
    return 0;
}
