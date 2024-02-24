#include <unistd.h> 
#include <stdio.h>

int is_not_printable(char ch)
{
    if (ch <= 31 || ch == 127)
    {
        return 1;
    }
    return 0;
}

void ft_putstr_non_printable(char *str)
{
    while (*str != '\0')
    {
        if(is_not_printable(*str))
        {
            write(1, '\\' , 1);
        }
        else
        {
            write(1, str, 1);
        }
        str++;
    }
    

}

int main(void)
{
    ft_putstr_non_printable("Coucou\ntu va\x7Fs bien ?");
    // printf("is not printable: %d", is_not_printable('\x7F'));
    return 0;
}