#include <stdio.h>

int main(void)
{
    int i = 7;
    int *p_i = &i;
    printf("%d\n", i);
    printf("%d\n", *p_i);
    return 0;
}