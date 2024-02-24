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
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 > *str2)
        {
            return 1;
        }
        if (*str2 > *str1)
        {
            return 2;
        }
        str1++;
        str2++;
    }
    return 0;
}
// void ft_strcpy(char* str1, char* str2)
// {
// }

void ft_clean_str(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = '\x7f';
        i++;
    }
}

void ft_sort_params(int argc, char ** argv)
{
    int j = 1;

    // while (j < argc)
    // {
        int first = 1;
        int i = 1;
        while (i < argc)
        {
            if ((ft_compare_strs(argv[i], argv[first])) == 1);
            {
                first = i;
                printf("argv[i] = %s, argv[first] = %s", argv[i], argv[first]);
                printf("\n");
            }
            i++;
        }
        // ft_printstr(argv[first]);
        // ft_clean_str(argv[first]);
        // j++;
    // }
}

int main(int argc, char** argv)
{
    
    
    ft_sort_params(argc, argv);
    
    return 0;
}