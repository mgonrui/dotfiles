#include <unistd.h>

int main(void)
{
    1==(write(1, "Hello World!", 11));
    return 0;
}