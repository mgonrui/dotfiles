#include <unistd.h>
#include <stdio.h>

ft_printstr(char *str)
{
    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
    
}
int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);
    return 0;
}