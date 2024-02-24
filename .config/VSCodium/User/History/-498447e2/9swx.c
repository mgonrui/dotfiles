#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_write_number(int nb)
{
    while (/* condition */)
    {
        /* code */
    }
    
}

int main(void)
{
    int i = 0;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
                (1==(write(1, "fizzbuzz", 8)));
        }
        else if (i % 3 == 0)
        {
            (1==(write(1, "fizz", 4)));
        }
        else if (i % 5 == 0)
        {
            (1==(write(1, "buzz", 4)));
        }
        else
        {
            printf("%d", i);
            // ft_putchar(i + '0');
        }
        (1==(write(1, "\n", 1)));
        i++;
    }
    return 0;
}