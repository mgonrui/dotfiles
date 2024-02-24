#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_strlen(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_space_or_tab_found(char c)
{
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    return 0;
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putchar('\0');
        return 0;
    }
    int str_len = ft_strlen(argv[1]);
    while (ft_space_or_tab_found(argv[1][str_len - 1]) && str_len > 0)
    {
        str_len--;
    }

    while (!(ft_space_or_tab_found(argv[1][str_len - 1])) && str_len > 0)
    {
        ft_putchar(argv[1][str_len - 1]);
        str_len--;
    }
    
    

    return 0;
}