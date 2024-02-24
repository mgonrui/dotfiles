#include <unistd.h>

char ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
int main(void)
{
    char letter = 'a';
    // while (letter <= 'z')
    // {
    //     if(letter % 2 == 0)
    //     {
    //         ft_putchar(letter + 32);
    //     }
    //     else
    //     {
    //         ft_putchar(letter);
    //     }
    //     letter++;
    // }
    #include <stdio.h>
    printf("%c", letter);
    
    return 0;
}