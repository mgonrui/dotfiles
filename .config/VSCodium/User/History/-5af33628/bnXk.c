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

}

int main(void)
{
    // ft_putstr_non_printable("Coucou\ntu vas bien ?");
    printf("is not printable: %d", is_not_printable('\n'));
    return 0;
}