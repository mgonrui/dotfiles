#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
void ft_printstr(char* str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }
}

int main(int argc, char** argv)
{
    
    int i = 0;
    while (i < argc)
    {
        ft_printstr(argv[i]);
        i++;
    }
    
    return 0;
}