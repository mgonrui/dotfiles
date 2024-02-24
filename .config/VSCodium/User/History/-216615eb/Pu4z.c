#include <unistd.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    int z =(write(1, "z", 1));
}
