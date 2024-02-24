int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}
char    *ft_strrev(char *str)
{
    int beggining_of_string = 0;
    int end_of_string = ft_strlen(str) - 1;
    char swap;
    while (beggining_of_string < end_of_string)
    {
        swap = str[beggining_of_string];
        str[beggining_of_string] = str[end_of_string];
        str[end_of_string] = swap;

        beggining_of_string++;
        end_of_string--;
    }
    
    return str;
}

#include <stdio.h>

int main(void)
{
    char str[] = "12345678";
    printf("%s\n", ft_strrev(str));
    return 0;
}

