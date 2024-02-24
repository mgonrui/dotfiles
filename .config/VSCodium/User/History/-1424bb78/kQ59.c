int ft_str_is_numeric(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= '0' && str[i] <= '9')) 
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    if (i == 0)
    {
        return 1;
    }
    return 10;
    

}

#include <stdio.h>

int main(void)
{
    char str[];
    printf("%d\n", ft_str_is_numeric(str));
}