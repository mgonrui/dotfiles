#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_printstr(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z')
        {
            if (!((string[i] + 13) >= 'a' && (string[i] + 13) <= 'z' || (string[i] +13) >= 'A' && (string[i] + 13) <= 'Z'))
            {
                ft_putchar(string[i] - 13);
            }
            else
            {
                ft_putchar(string[i] + 13);
            }
        }
        else
        {
            ft_putchar(string[i]);
        }
        i++;
    }
    ft_putchar('\n');
}

int main(void)
{
    // ft_printstr("My horse is Amazing.");
    ft_printstr("O");
    // printf("%c\n", 'N' - 13);
    return 0;
}