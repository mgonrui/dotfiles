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
    }
    return 0;
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
        while (str1[i] != '\0')
        {
            printf("%d\n", j);
            if (!(ft_match(str1[i], matches)))
            {
                matches[j] = str1[i];
                printf("%d\n", j);
                j++;
            }
            i++;
        }
        i = 0;
        // while (str2[i] != '\0')
        // {
        //     if (!(ft_match(str2[i], matches)))
        //     {
        //         matches[j] = str2[i];
        //         j++;
        //     }
        //     i++;
        // }
        printf("%s", matches);
    }
    ft_putchar('\n');

    return 0;
}