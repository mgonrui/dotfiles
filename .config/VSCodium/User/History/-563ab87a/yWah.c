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
// value = 0 : str1 == str2. value = -n : str1 < str2. value = +n : str1 > str2
int ft_compare_strings (char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    return 0;
}

// void ft_str_swap(char *str1, char *str2)
// {
//     int i = 0;
//     while (str1[i] != '\0' && str2[i] != '\0')
//     {
//         i++;
//     }
    
// }

// void ft_sort_params()

int main(int argc, char *argv[])
{
    int i, j = 1, largest_position;
    while (j < argc)
    {
        char biggest_arg[100];  
        char *p_biggest_arg = biggest_arg;
        i = 1;
        while (i < argc)
        {
            if (ft_compare_strings(argv[i], p_biggest_arg) >= 1)
            {
                p_biggest_arg = argv[i]; 
                largest_position = i;
            }
            i++;
        }
        // printf("%s\n", p_biggest_arg);
        ft_printstr(p_biggest_arg);
        j++;
        argv[largest_position] = "\0";
    }
    return 0;
}