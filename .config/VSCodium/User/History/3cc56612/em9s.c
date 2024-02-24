#include <stdio.h>
#define DISP(f,x) (printf("f(%g) = %g\n", x, f(x)))

int main(void)
{
    int sqrt(int n)
    { 
        return (n * n);
    }
    DISP(sqrt, 3.0);
    return 0;
}
