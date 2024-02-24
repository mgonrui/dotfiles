#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    
    return i;
}

char *ft_rev_print (char *str)
{
    int strlen = ft_strlen(str) - 1;
    while (strlen > 0)
    {
        (1==(write(1, str[strlen], 1)));
        strlen--;
    }
    


}