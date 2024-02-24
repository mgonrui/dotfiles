#include <stdio.h>
#include <stdlib.h>


int ft_is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

// jumps spaces and returns the sign of the following number
int ft_signs_and_spaces(char **str)
{
    int sign = 1;
    while (!ft_is_digit(**str))
    {
        if (**str == '-')
        {
            sign *= -1;
        }
        (*str)++;
        // printf("%s\n", str);
    }
    // printf ("%d\n", sign);
    return sign;
    
} 

int ft_atoi(char *str)
{
    int nbr = 0;
    char *p_str = str;
    ft_signs_and_spaces(&p_str);
    // printf("%c\n", p_str[0]);
    // p_str++;
    // printf("%s\n", p_str);
    // while (*p_str > '0' && *p_str < '9')
    // {
    //     nbr *= 10;
    //     nbr += *p_str - '0';
    //     p_str++;
    // }
    return nbr;
}

int main(void)
{
    char *str = "-- - + ---1234ab567";
    // printf("%d\n", ft_atoi(str));
    printf("%s\n",ft_signs_and_spaces(str));
    // atoi(str);
    // printf("%d\n", );
    return 0;
}