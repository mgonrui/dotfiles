#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putchar('\n');
        return 0;
    }
    int i = 0;
    while (argv[1][i] != '\0')
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            if ((argv[1][i] + 1 >= 'a' && argv[1][i] + 1 <= 'z') || (argv[1][i] + 1 >= 'A' && argv[1][i] + 1 <= 'Z'))
            {
                ft_putchar(argv[1][i] + 1);
            }
            else
            {
                ft_putchar(argv[1][i] - 25);
            }
        }
        else
        {
                ft_putchar(argv[1][i]);
        }
        i++;
    }
    return 0;
}