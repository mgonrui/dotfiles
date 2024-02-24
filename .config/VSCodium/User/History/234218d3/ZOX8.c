#include <stdio.h>

int main(void)
{
    int i = 7;
    int *p_i = &i;
    int **pp_i = &p_i;
    printf("%d\n", i);
    printf("%d\n", *p_i);
    printf("%d\n", **pp_i);
    return 0;
}