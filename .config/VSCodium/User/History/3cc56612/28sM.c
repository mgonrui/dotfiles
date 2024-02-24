#include <stdio.h>

#define NELEMS(a) (sizeof (a) * sizeof (a[0]))


int main(void)
{
    printf("%ld", NELEMS("hello world!!!"));
    return 0;
}
