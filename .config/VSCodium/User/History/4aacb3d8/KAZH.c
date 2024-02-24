#include <unistd.h>
#include <stdio.h>

int i = 1;
char letter = 'A';

int main(void)
{
    // printf("%d\n",diff);
    while (letter < 'z') 
    {
        if(i % 2 == 0)
        {
            write(1, &letter, 1);
        }
        else
        {
            write(1, &letter + 32, 1);
        }
        i++;
        letter++;
    }
}



