#include <stdio.h>
#include <string.h>

void ft_putnbr_base(int nbr, char *base)
{
    int i = 0, j = 0, coinc = 0;
    while (base[j] != '\0')
    {
        i = 0;
        coinc = 0;
        while (base[i] != '\0')
        {
            if (base[i] == '-' || base[i] == '+')
            {
                return;
            }
            if (base[i] == base[j])
            {
                coinc++;
            }
            if (coinc > 1)
            {
                return;
            }
            i++;
        }
        j++;
    }
    if (j <= 1)
    {
        return;
    }
    
    printf("not null");
}

int main(void)
{
    int nbr = 42;
    char *base[] = { "0123456789", "01", "0123456789ABCDEF", "01234567"};
    // ft_putnbr_base(nbr, base[0]);
    ft_putnbr_base(nbr,"12341" );
    return 0;
}