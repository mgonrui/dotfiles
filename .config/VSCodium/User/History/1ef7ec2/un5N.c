#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int count = min;
    int *arr = malloc(max *(sizeof (int)));
    int *p_arr = arr;
    if (arr == NULL)
    {
        return NULL;
    }
    if (min > max)
    {
        return NULL;
    }
    while (count < max)
    {
        *arr = count++;
        arr++;
    }
    return p_arr;
}

int main(void){
    for (int i=0; i < 2; i++)
    {
        printf("%d",(ft_range(2, 1))[i]);
    }
;
    return 0;
}