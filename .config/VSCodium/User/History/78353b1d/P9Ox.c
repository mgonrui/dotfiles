#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_letter_found(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        
    }
    ft_putchar('\n');
    return 0;
}