#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[i])
        {
            char c = argv[1][i];  

            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                c += 1;
            }
            else if (c == 'z' || c == 'Z')
            {
                c -=25;
            }
            ft_putchar(c);
            i++;
        }
        

    }
    ft_putchar('\n');
}