#include <unistd.h>

char ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
int main(void)
{
    char letter = 'a';
    while (letter <= 'z')
    {
        if(letter % 2 == 0)
        {
            ft_putchar(letter + 32);
        }
        else
        {
            (1==(write(1, &letter, 1)));
        }
        letter++;
    }
    
    return 0;
}