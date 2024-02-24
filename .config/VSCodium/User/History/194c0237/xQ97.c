#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_is_non_printable(char c)
{
    if (c <= 31 || c == 127)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (ft_is_non_printable(str[i]))
        {
        }
        i++;
    }
}

int main(void)
{
    char str[] = "hello\n wor\x7fld!!!";
    // ft_putstr_non_printable(str);
    ft_putchar('c');
    return 0;
}