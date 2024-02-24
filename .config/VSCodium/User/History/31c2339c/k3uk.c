#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int n)
{
    int i = 0;
    int j = 1;
    int k = 0;
    int l = 0;
    int digits[n];
    while (l < n)
    {
        digits[l++] = 0;
    }
    while (digits[0] < 12 - n)
    {
            // printf("hello");
        while (digits[n - j] < 10 - j)
        {
            printf("hello");
            digits[n - j] =  digits[n - j] + 1;
            // while (k < n)
            // {
            //     printf("%d", digits[k]);
            //     k++;
            // }
            
        }
        
    }
    
}

int main(void)
{
    int n = 2;
    ft_print_combn(n);
    return 0;
}
