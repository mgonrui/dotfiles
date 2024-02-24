#include <unistd.h>

int main(void)
{
    (1==(write(1, 'a', 1)));
    return 0;
}