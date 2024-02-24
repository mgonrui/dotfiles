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

int main(int argc, char *argv[])
{
    int i, j = 1, lowest_position;
    while (j < argc)
    {
        char lowest_arg[100];  
        char *p_lowest_arg = lowest_arg;
        i = 1;
        while (i < argc)
        {
            if (ft_compare_strings(argv[i], p_lowest_arg) >= 1)
            {
                p_lowest_arg = argv[i]; 
                lowest_position= i;
            }
            i++;
        }
        ft_printstr(p_lowest_arg);
        j++;
        argv[lowest_position] = "\x7F";
    }
    return 0;
}