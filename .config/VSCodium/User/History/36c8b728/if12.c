#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_number_of_items_in_arr(char **strs)
{

    // return sizeof (*strs[0]);
    return (sizeof (strs) / sizeof (*strs[0]));
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    // char *strjoin = (char *)malloc();
}

int main(void)
{
    char *strs[] = {"hello", "world", "!!!"};
    char *sep = "_-_";
    printf("%d\n", ft_number_of_items_in_arr(strs));
    return 0;
}