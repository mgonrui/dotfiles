#include <stdio.h>
#include <unistd.h>

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

int ft_union(char *str1, char *str2, int j)
{
    int i = 0; 
    while (str1[i] != '\0')
    {
        if (!(ft_match(str1[i], str2)))
        {
            str2[j++] = str1[i];
        }
        i++;
    }
    return j;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int j = 0;
        char chars[100];
        j = ft_union(argv[1], chars, j);
        j = ft_union(argv[2], chars, j);
        int i = 0;
        while (chars[i] != '\0')
        {
            ft_putchar(chars[i]);
            i++;
        }
        
    }
    ft_putchar('\n');
    return 0;
}
