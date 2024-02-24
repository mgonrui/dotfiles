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
        digits[l] = 0;
        l++;
    }
    while (digits[0] < 10 - n)
    {
            while ((digits[n - j]) <= 9)
            {
                printf("%d\n", digits[n -j]);
                digits[n - j]++;
            }
                digits[n - j] = 0;
        
    }
    
}

int main(void)
{
    int n = 3;
    ft_print_combn(n);
    return 0;
}
