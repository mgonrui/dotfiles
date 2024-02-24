#include <unistd.h>
#include <stdio.h>

int ft_letter_found(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char **argv)
{
    printf("%d\n", ft_letter_found('2'));
    return 0;
}