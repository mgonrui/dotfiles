#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_letter_found(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i])
        {
            char c = argv[1][i];
            if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
            {
                ft_putchar(c + 13);
            }
            else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
            {
                ft_putchar(c - 13);
            }
            i++;
        }
        
        
    }
    ft_putchar('\n');
    return 0;
}