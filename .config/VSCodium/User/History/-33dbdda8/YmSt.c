int ft_str_is_alpha(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
    

}

#include <stdio.h>

int main(void)
{
    char str[] = "1234567890a";
    printf("%d\n", ft_str_is_alpha(str));
}