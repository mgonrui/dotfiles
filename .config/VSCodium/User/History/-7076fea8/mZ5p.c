#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_match(char c, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

char *ft_find_matches(char *str1, char *str2)
{
    int i = 0;
    int k = 0;
    char *matches = (char *)malloc(sizeof (char) * 100);
    while (str1[i] != '\0')
    {
        if (ft_match(str1[i], str2))
        {
            if (!(ft_match(str1[i], matches)))
            {
                matches[k] = str1[i];
                k++;
            }
        }
        i++;
    }
    // matches[k] = '\0';
    return matches;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *matches = ft_find_matches(argv[1], argv[2]);
        printf("%s", matches);
    }
    ft_putchar('\n');
    return 0;
}