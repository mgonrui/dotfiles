#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_strlen(char *str)
{
    int length = 0;
    while (str[length])
    {
        length++;
    }
    
    return length;
}

char match_found(char *str, char c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return 0;
    }
    char matches[ft_strlen(argv[1])];
    int match_slot = 0;
    int i = 0;
    while (argv[1][i] != '\0')
    {
        if (match_found(argv[2], argv[1][i]) != -1)
        {
            if (match_found(matches, argv[1][i]) == -1)
            {
                matches[match_slot++] = argv[1][i];
            }
        }
        i++;
    }
}

