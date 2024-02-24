#include <unistd.h>
#include <stdio.h>

int ft_delimiter_found(char c)
{
    if (c == ' ' || c == '\t')
    {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    char *str = argv[1];
    int end_str = 0;
    while (str[end_str] != '\0')
    {
        end_str++;
    }
    // printf("%c", str[end_str]);
    
    
    return 0;
}