#include <unistd.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    (1==(write(1, "z", 1)));
}
