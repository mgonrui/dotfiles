#include <unistd.h>
void ft_putstr(char *str)
{
    int i = 0;
    while ( i++ < sizeof(*str) / sizeof(str[0]))
    {
        write(1, str++, 1);
        
    }
    

}

int main(void)
{
    char str[] = "hello world";
    ft_putstr(str);
    return 0;
}