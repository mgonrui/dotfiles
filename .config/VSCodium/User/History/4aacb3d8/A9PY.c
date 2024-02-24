#include <unistd.h>
#include <stdio.h>

int i = 1;
char letter = 'A';
char diff = 'a' - 'A'; // 32

int main(void)
{
    // printf("%d\n",diff);
    while (letter < 'z') 
    {
        if(i % 2 == 0)
        {
            write(1, letter, 1);
        }
        i++;
        letter++;
    }
}



