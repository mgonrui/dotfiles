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
    return i - 1;
}

char *ft_rev_print (char *str)
{
    int endstr = ft_strlen(str);
    while (endstr >= 0)
    {
        ft_putchar(str[endstr]);
        endstr--;
    }
    return str;
}

int main(void)
{
    char *str = "hello world!!!";
    ft_rev_print(str);
    return 0;
}