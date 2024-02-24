#include <unistd.h>

int main(void)
{
    char c = 'z';
    write(1, &c, 1);
    write(1, "\n", 1);
    return 0;
}