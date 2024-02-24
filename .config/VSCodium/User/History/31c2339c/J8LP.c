#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int n)
{
    int i = 0;
    int j = 1;
    int k = 0;
    int digits[n];
    while (digits[0] < (10 - n))
    {
        while (digits[n - j] < (n - j))
        {
            digits[n - j]++;
            while (k < n)
            {
                printf("%d", digits[k]);
                k++;
            }
            
        }
        
    }
    
}

int main(void)
{
    int n = 2;
    ft_print_combn(n);
    return 0;
}
