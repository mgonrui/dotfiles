#include <unistd.h>
#include <stdio.h>

void ft_printstr(char *str)
{
    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
    
}
int main(int argc, char *argv[])
{
    // while (argc > 1)
    // {
        ft_printstr(argv[argc]);
        // argc--;
    // }
    
    return 0;
}