#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
    (1==write(1, &c, 1));
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_no_words(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {

        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2 || ft_no_words(argv[1]))
    {
        ft_putchar('\n');
        return 0;
    }
    ft_putchar('a');

    return 0;
}