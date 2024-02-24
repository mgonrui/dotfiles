#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_delimeter_found(char c)
{
    if (c == ' ' || c == '\t' || c == '\0')
    {
        return 1;
    }
    return 0;
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        int i = 0;
        while (ft_delimeter_found(argv[1][i]))
        {
            i++;
        }
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
        // while (!ft_delimeter_found(argv[1][i]))
        {
            ft_putchar(argv[1][i]);
            // (1==(write(1, &argv[1][i], 1)));
            i++;
        }
    }
    ft_putchar('\n');
    return 0;

}