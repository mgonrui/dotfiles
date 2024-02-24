#include <unistd.h>

void ft_is_negative(int n)
{
    if (n < 0)
    {
        write(1, 'N', 1);
    }
    
}

int main(void){
    int num = -3;
    void ft_is_negative(num);
    return 0;
}