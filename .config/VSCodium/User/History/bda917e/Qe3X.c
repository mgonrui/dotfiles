#include <unistd.h>
#include <stdio.h>


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
void ft_search_nonmatches(char *str, char *matches, int matches_pos)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!(ft_match(str[i], matches)))
        {
            matches[matches_pos] = str[i];
            matches_pos++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int j = 0;
        char *str1 = argv[1];
        char *str2 = argv[2];
        char matches[100];
        int matches_pos = 0;
        ft_search_nonmatches(str1, matches, matches_pos)
        while (str2[i] != '\0')
        {
            if (!(ft_match(str2[i], matches)))
            {
                matches[j] = str2[i];
                j++;
            }
            i++;
        }
        i = 0;
        while (matches[i] != '\0')
        {
            ft_putchar(matches[i]);
            i++;
        }
        
    }
    ft_putchar('\n');

    return 0;
}