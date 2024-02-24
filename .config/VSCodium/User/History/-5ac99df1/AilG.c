#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_char_match(char c, char *str, int position)
{
    while (str[position] != '\0')
    {
        if (str[position] == c)
        {
            return position;
        }
        position++;
    }
    return -1;
}
int ft_wor_match(char *str1, char *str2)
{
    int i = 0;
    int position = 0;
    while (str1[i] != '\0')
    {
        if (ft_char_match(str1[i], str2, position) == -1)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return 0;
    }
    // printf("%s\n", argv[1]);
    if (ft_wor_match(argv[1], argv[2]))
    {
        printf("%s\n", argv[1]);
    }
    else 
    {
        printf("no match\n");
    }


}