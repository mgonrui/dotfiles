#include <unistd.h>

int main(void)
{
    (1==(write(1, "z", 1)));
    return 0;
}