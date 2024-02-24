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
        while (argv[i])
        {
            char c = argv[1][i];  

            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                argv[1][i] += 1;
            }
            else if (c == 'z' || c == 'Z')
            {
                argv[1][i] -=25;
            }
            (1==(write(1, &argv[1][i], 1)));
            i++;
        }
        

    }
    ft_putchar('\n');
}