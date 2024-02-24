#include <unistd.h>

int main(void)
{
    char letter = 'a';
    while (letter <= 'z')
    {
        if(letter % 2 == 0)
        {
            (1==(write(1, &letter + 1, 1)));
        }
        else
        {
            (1==(write(1, &letter, 1)));
        }
        letter++;
    }
    
    return 0;
}