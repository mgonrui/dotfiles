#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_print_alphabet(void)
{
    char letter  = 'a'; 
    while (letter <= 'z')
    {
        ft_putchar(letter);
        letter++;
    }
    
    
}

int main(void)
{
    // printf("%s\n", ft_print_alphabet);
    ft_print_alphabet();
    return 0;
}