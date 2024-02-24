#include <unistd.h>
#include <stdio.h>

void ft_hex_converter(char *ch)
{
    char converted[2];
    char hexnumbers[] = "0123456789abcdef";
    converted[0] = hexnumbers[*ch / 16];
    converted[1] = hexnumbers[*ch % 16];
    write(1, converted, 1);
    write(1, converted + 1, 1);
}

int ft_is_not_printable(char ch)
{
    if (ch <= 31 || ch == 127)
    {
        return 1;
    }
    return 0;
}

void *ft_print_memory(void *addr, unsigned int size)
{
    if (size == 0)
    {
        return addr;
    }
    return addr;
}

int main(void)
{
    ft_print_memory("Bonjour les amin", 10);
    return 0;
}