#include <unistd.h>
#include <stdio.h>


int ft_delimeter_found(char c)
{
    if (c == ' ')
    {
        return 1;
    }
}
int main(int argc, char **argv)
{
    char* str =  " a";
    ft_delimeter_found(str[1]);

}