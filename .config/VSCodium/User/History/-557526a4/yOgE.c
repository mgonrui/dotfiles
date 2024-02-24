#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

void ft_printstr(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            if ((string[i] + 13) > 'z')
            {
                ft_putchar(string[i] - 13);
            }
            else
            {
                ft_putchar(string[i] + 13);
            }
        }

        else if(string[i] >= 'A' && string[i] <= 'Z')
        {
            if ((string[i] + 13) > 'Z')
            {
                ft_putchar(string[i] - 13);
            }
            else
            {
                ft_putchar(string[i] + 13);
            }
        }
        else
        {
            ft_putchar(string[i]);
        }
        i++;
    }
    ft_putchar('\n');
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putchar('\n');
        return 0;
    }
    ft_printstr(argv[1]);
    return 0;
}