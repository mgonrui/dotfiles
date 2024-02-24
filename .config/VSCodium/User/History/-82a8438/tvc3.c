#include <unistd.h>
void ft_putstr(char *str)
{
    while (sizeof(str[0]) / sizeof(str))
    {
        write(1, str, 1);
    }
    

}

#include <stdio.h>

int main(void)
{
    char str[] = "hello world";
    // ft_putstr(str);
    printf("%d\n", sizeof(str[0]) / sizeof(str));
    return 0;
}