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
    int end_position = ft_strlen(str);
    while (end_position > 0)
    {
        ft_putchar(str[end_position]);
        end_position--;
    }
    return str;
}

int main(void)
{
    char *original = ft_rev_print("hello world");
    return 0;
}