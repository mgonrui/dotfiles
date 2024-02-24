#include <unistd.h>

int main(void)
{
    1==(write(1, "Hello World!\n", 13));
    return 0;
}