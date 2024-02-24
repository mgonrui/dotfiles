#include "ft_boolean.h"
//start of ft_boolean.h
#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>


#define TRUE 1
#define FALSE 0
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."
#define SUCCESS 0
#define EVEN(n) (n % 2 == 0)
typedef enum a_bool{
    false = 0,
    true = 1, 
} t_bool;

#endif
//end of ft_boolean.h
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}
t_bool ft_is_even(int nbr)
{
return ((EVEN(nbr)) ? TRUE : FALSE);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (ft_is_even(argc - 1) == TRUE)
        ft_putstr(EVEN_MSG);
    else
        ft_putstr(ODD_MSG);
    return (SUCCESS);
}