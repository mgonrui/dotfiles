#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stock_str
{
    int size;
    char* str;
    char* copy;
} t_stock_str;

void ft_printstr(char* str)
{
    int i = 0;
    while (*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
    write (1 , "\n", 1);
}

int ft_strlen(char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
char* ft_strcpy(char* str)
{
    int i = 0;
    char* str_copy;
    str_copy = (char* )malloc(sizeof (char) + ft_strlen(str) + 1);
    if (!str_copy)
    {
        return NULL;
    }
    while (str[i] != '\0')
    {
        str_copy[i] = str[i];
        i++;
    }
    return str_copy;
}

struct s_stock_str *ft_strs_to_tab(int ac, char** av)
{
    int i = 0;
    struct s_stock_str* array_structs;
    array_structs = malloc((ac + 1) * sizeof(struct s_stock_str));
    if (!array_structs)
    {
        return NULL;
    }
    while (i < ac)
    {
        array_structs[i].size = ft_strlen(av[i]); 
        array_structs[i].str = av[i]; 
        array_structs[i].copy = ft_strcpy(av[i]); 
        i++;
    }
    array_structs[i].str = 0; 
    return (array_structs);
}
void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while (i < 3)
    {
        // ft_printstr(par[i].str);
        // ft_printstr(par[i].copy);
        // write (1, (par[i].size + '0'), 1);
        i++;
    }

}

int main(void)
{
    int ac = 3;
    int sel = 2;
    char* av[3] = {"string1", "string2", "string3"};
    // ft_strs_to_tab(ac, av);
    struct s_stock_str* array_structs = (ft_strs_to_tab(3, av));
    ft_show_tab(array_structs);
    printf("size: %d\n", array_structs[sel].size);
    printf("string: %s\n", array_structs[sel].str);
    printf("copy: %s\n", array_structs[sel].copy);

    return 0;
}