#include <unistd.h>
#include <stdio.h>

int i = 1;
char letter = 'A';

char ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    // printf("%d\n",diff);
    while (letter < 'z') 
    {
        if(i % 2 == 0)
        {
            write(1, &letter, 1);
        }
        if(i % 2 != 0)
        {
            ft_putchar(letter + 32);
        }
        i++;
        letter++;
    }
}



