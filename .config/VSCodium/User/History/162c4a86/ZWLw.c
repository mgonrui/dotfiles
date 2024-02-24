#include <unistd.h>

int main(void)
{
    char i = '9';
    while (i > '0')
    {
        (1==(write(1, &i, 1)));
        i--;
    }
    
    return 0;
}