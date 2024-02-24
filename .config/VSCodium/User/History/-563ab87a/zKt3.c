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
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return (*str1 - *str2);
        }
            str1++;
            str2++;
    }
    return 0;
}

void ft_str_swap(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        i++;
    }
    
}
// int main(int argc, char *argv[])
int main(void)
{
    // int i = 1;
    // while (i < argc)
    // {
    //     ft_printstr(argv[i]);
    //     i++;
    // }
    char *str1 = "4", *str2 = "6";
    printf("%d\n",ft_compare_strings(str1, str2));
    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return 0;
}