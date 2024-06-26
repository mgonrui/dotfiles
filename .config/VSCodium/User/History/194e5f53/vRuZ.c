#include <unistd.h>
#include <stdio.h>


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
int ft_compare_strs(char* str1, char* str2)
{
    while (*str1 == *str2)
    {
        str1++;
        str2++;
    }
    if (*str1 != *str2)
    {
        return (*str1 - *str2);
    }
}
// void ft_strcpy(char* str1, char* str2)
// {
// }

void ft_sort_params(int argc, char ** argv)
{
    int i = 1;
    int j = 1;
    int first = 1;

    while (i < argc)
    {
        if (ft_compare_strs(argv[i], argv[first]) > 0);
        {
            first = i;
        }
        i++;
    }
    // ft_printstr(argv[first]);
    // printf("%s", argv[first]);
    // printf("%s", argv[1]);
}

int main(int argc, char** argv)
{
    
    
    ft_sort_params(argc, argv);
    ft_printstr(argv[1]);
    
    return 0;
}