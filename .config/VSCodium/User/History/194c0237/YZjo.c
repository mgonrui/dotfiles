#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
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

void ft_hex_converter(char c)
{
    char* hex = "0123456789abcdef";
    ft_putchar(hex[c / 16]);
    ft_putchar(hex[c % 16]);
}

void ft_putstr_non_printable(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (ft_is_non_printable(str[i]))
        {
            ft_putchar('\\');
            ft_hex_converter(str[i]);
        }
        else
        {
            ft_putchar(str[i]);
        }
        i++;
    }
}

int main(void)
{
    char str[] = "hello\n wor\x7f";
    ft_putstr_non_printable(str);
    return 0;
}