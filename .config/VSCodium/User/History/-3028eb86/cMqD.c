#include <stdio.h>
#include <stdlib.h>

typedef struct s_stock_str
{
    int size;
    char* str;
    char* copy;
} t_stock_str;
int ft_strlen(char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
}
struct s_stock_str *ft_strs_to_tab(int ac, char** av)
{

}

int main(void)
{
    int ac = 3;
    char** av = {"string1", "string2", "string3"};
    ft_strs_to_tab(ac, av);

    return 0;
}