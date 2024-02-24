#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
    int count = min;
    int *arr; 
    int *p_arr;

    if (min >= max)
    {
        return NULL;
    }

    arr = malloc((max - min) *(sizeof (int)));
    p_arr = arr;

    if (arr == NULL)
    {
        return 0;
    }
    while (count < max)
    {
        *arr = count++;
        arr++;
    }
    return p_arr;
}

int main(void){
    int min = 50, max = 10;
    if (ft_range(min, max) == NULL)
    {
        printf("NULL was returned\n");
    }
    else
    {
        for (int i=0; i < (max - min); i++)
        {
            printf("%d ",(ft_range(min, max))[i]);
        }
        printf("\n");
    }
    return 0;
}