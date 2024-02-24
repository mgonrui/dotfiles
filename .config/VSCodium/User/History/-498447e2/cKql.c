#include <unistd.h>



int main(void)
{
    int i = 0;
    while (i <= 100)
    {
        if (i % 3 == 0)
        {
            if (i % 5 == 0)
            {
                (1==(write(1, "fizzbuzz", 8)));
            }
            else
            {
                (1==(write(1, "fizz", 4)));
            }
        }
        else if (i % 5)
        {
            (1==(write(1, "buzz", 4)));
        }
        else
        {
            (1==(write(1, &i, 1)));
        }
        i++;
    }
    return 0;
}