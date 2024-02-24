#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
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
char *ft_rev_print (char *str)
{
    int end_position = ft_strlen(str) - 1;
    while (end_position >= 0)
    {
        ft_putchar(str[end_position]);
        end_position--;
    }
    ft_putchar('\n');
    return str;
}

#include <stdio.h>

int main(void)
{
    char *original = ft_rev_print("dub0 a POIL");
    printf("%s\n", original);
    return 0;
}