#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}
int ft_is_match(char c, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
void ft_store_nonmatches(char *str, char *characters, int *characters_position)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(!(ft_is_match(str[i], characters)))
        {
            characters[*characters_position] = str[i];
            i++;
            *characters_position++;
        }
    }
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int characters_position = 0;
        char *str1 = argv[1];
        char *str2 = argv[2];
        char *characters;
        ft_store_nonmatches(str1, characters, &characters_position);
        // ft_store_nonmatches(str2, characters, &characters_position);
        printf("%s", characters);
    }
    ft_putchar('\n');
    return 0;
}