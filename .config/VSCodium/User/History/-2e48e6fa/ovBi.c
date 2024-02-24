#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

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
    if (argc == 2)
    {
        char *str = argv[1];
        int end_str = 0;
        while (str[end_str + 1] != '\0')
        {
            end_str++;
        }
        while (ft_delimiter_found(str[end_str]))
        {
            end_str--;
        }
        int start_str = end_str;
        while (!(ft_delimiter_found(str[start_str])) && start_str > 0)
        {
            start_str--;
            // printf("%c\n", str[start_str]);
        }
        while (start_str <= end_str)
        {
            ft_putchar(str[start_str]);
            start_str++;
        }
        

        
        // printf("%c\n", str[start_str]);
        // printf("%c\n", str[end_str]);
    }
    ft_putchar('\n');
    
    return 0;
}