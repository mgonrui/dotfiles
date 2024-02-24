#include <stdio.h>

int ft_str_is_lowercase(char *str)
{
    int i = 0;
    while (str[i + 1] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str++;
        }
        else
        {
            return 0;
        }
    }
    

}

int main(void)
{
    char *str = "abcd";
    printf("%d\n", ft_str_is_lowercase(str));
    return 0;
}