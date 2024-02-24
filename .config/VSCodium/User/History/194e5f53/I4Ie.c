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
void ft_sort_params(int argc, char ** argv)
{
    while (argc--)
    {
    }
    

}

int main(int argc, char** argv)
{
    
    printf("%d", ft_compare_strs("h2llo", "h1rld"));
    
    // ft_sort_params(argc, argv);
    
    return 0;
}