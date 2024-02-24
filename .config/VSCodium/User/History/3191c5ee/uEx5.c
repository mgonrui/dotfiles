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
int ft_signs_and_spaces(char *str, int *p_i)
{
    int sign = 1, i = 0;
    while (!ft_is_digit(str[i]))
    {
        if (str[i] == '-')
        {
            sign *= -1;
        }
        i++;
        // printf("%s\n", str);
    }
    // printf ("%d\n", sign);
    *p_i = (i + 1);
    return sign;
    
} 

int ft_atoi(char *str)
{
    int nbr = 0;
    int i;
    char *p_str = str;
    int sign = ft_signs_and_spaces(p_str, &i);
    while (p_str[i] > '0' && p_str[i] < '9')
    {
        nbr *= 10;
        nbr += p_str[i] - '0';
        i++;
    }
    return (nbr * sign);
}

int main(void)
{
    char *str = "--1234ab567";
    printf("%d\n", ft_atoi(str));
    // printf("%s\n",ft_signs_and_spaces(str));
    // atoi(str);
    // printf("%d\n", );
    return 0;
}