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
int main(int argc, char **argv)
{
    // if (argc != 3)
    // {
    //     ft_putchar('\n');
    //     return 0;
    // }
    // char matches[] = ;
    printf("%d\n", ft_strlen("123456"));
    
}

