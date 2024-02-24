#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
int main(int argc, char **argv)
{

    if (argc >= 2)
    {
        int i = 0;
        while (argv[argc - 1][i] != '\0')
        {
            ft_putchar(argv[argc - 1][i]);
            i++;
        }
        

    }
    ft_putchar('\n');
    return 0;
}