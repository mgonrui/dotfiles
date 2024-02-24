#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
void ft_print_digits(int *arr, int n)
{
    int i = 0;
    while (i < n)
    {
        ft_putchar(arr[i] + '0');
        i++;
    }
    
}

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
                ft_print_digits(digits);
                ft_putchar(',');
                ft_putchar(' ');
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
