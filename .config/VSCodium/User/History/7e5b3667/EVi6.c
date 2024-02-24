#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        (1==(write(1, str[i], 1)));
        i++;
    }
    

}

int main(void)
{
    ft_putstr("hello world!!!");
    return 0;
}