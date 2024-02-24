#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int ft_error(char* base)
{
    if (ft_strlen(base) <= 1)
    {
        return 1;
    }
    int i = 0;
    while (base[i] != '\0')
    {
        if ( base[i] == '+' || base[i] == '-' || base[i] == ' ')
        {
            return 1;
        }
        int j = i + 1;
        while (base[j] != '\0')
        {
            if (base[j] == base[i])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    
}

int ft_atoi_base(char *str, char *base)
{

}

int main(void)
{
    printf("%d\n", ft_error("asdfg"));
    return 0;
}