#include <unistd.h>

void ft_is_negative(int n)
{
    if (n < 0)
    {
        write(1, 'N', 1);
    }
    
}

int main(void){
    void ft_is_negative(-3);
    return 0;
}