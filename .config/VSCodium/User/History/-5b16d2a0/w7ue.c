#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);
    write(1, '\n', 1);
    return 0;
}