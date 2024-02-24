#include <stdio.h>

#define NELEMS(a) (sizeof (a) / sizeof (a[0]))


int main(void)
{
    char arr[] = "hello world!!!";
    printf("%ld", NELEMS(arr));
    return 0;
}
