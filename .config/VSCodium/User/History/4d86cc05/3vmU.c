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
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putchar('\0');
        return 0;
    }
    int str_len = ft_strlen(argv[1]);
    while (str_len > 0)
    {
        if (argv[1][str_len - 1] == ' ' || argv[1][str_len - 1] == '\t')
        {
            str_len--;
            continue;
        }
    }
    

    return 0;
}