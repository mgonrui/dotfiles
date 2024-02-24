#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] != '\0')
        {
            i++;
        }
        i--;
        while (argv[1][i] == '\t' || argv[1][i] == 32)
        {
            i--;
        }
        int end_of_word = i;
        while (!(argv[1][i] == '\t' || argv[1][i] == 32))
        {
            i--;
        }
        int start_of_word = i;
        while (start_of_word <= end_of_word)
        {
            ft_putchar(argv[1][start_of_word++]);
        }
    }
    return 0;
}