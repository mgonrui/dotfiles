#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_match(char c, char *str, int *pos)
{
    while (str[*pos] != '\0')
    {
        if (str[*pos] == c)
        {
            return 1;
        }
        (*pos)++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *str1 = argv[1];
        char *str2 = argv[2];
        int i = 0;
        int pos = 0;
        while (str1[i] != '\0')
        {
            if (ft_match(str1[i], str2, &pos))
            {
                i++;
            }
            else
            {
                break;
            }
            printf("%s", str1);
        }
        

    }
    ft_putchar('\n');
}