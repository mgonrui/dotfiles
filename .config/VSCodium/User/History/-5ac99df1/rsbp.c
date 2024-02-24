#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    (1==(write(1, &c, 1)));
}

int ft_match(char c, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] = c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int ft_entire_match(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int ft_wdmatch(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    while (str2[i] != '\0')
    {
        if (ft_match(str2[i], str1))
        {
            char *p_str2 = &str2[i];
            if (ft_entire_match(*p_str2, str1))
            {
                return 1;
            }
        }
        i++;
    }
    return 0;
    
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_putchar('\n');
        return 0;
    }
    if (ft_wdmatch(argv[1], argv[2]))
    {
        printf("%s\n", argv[1]);
    }

}