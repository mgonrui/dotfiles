#include <stdio.h>
#define CUBE(x) (x * x)cube 
#define REMAINDER(n) (n % 4)
#define PRODUCT(x, y) (x * y < 100 ? 1 : 0)

int main(void)
{
    // printf("%d\n",CUBE(4));
    // printf("%d\n",REMAINDER(7));
    printf("%d\n",PRODUCT(30, 4));
    return 0;
}