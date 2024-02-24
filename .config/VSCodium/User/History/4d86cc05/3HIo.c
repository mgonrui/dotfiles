#include <stdio.h>
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
        while (argv[1][i] != '\0')
        {
            i++;
        }
        i--;
        while (argv[1][i] == '\t' || argv[1][i] == 32)
        {
            i--;
        }
        int end_of_word = i;
        while (!(argv[1][i] == '\t' || argv[1][i] == 32))
        {
            i--;
        }
        int start_of_word = i;
        while (start_of_word <= end_of_word)
        {
            ft_putchar(argv[1][start_of_word++]);
        }
    }
    ft_putchar('\n');
    return 0;
}



// #include <unistd.h>
// void	last_word(char *str)
// {
// 	int	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	i -= 1;
// 	while(str[i] == '\t' || str[i] == 32)
// 		i--;
// 	while (i > 0)
// 	{	if(str[i] == 32 && str[i] == '\t')
// 			break;
// 		i--;
// 	}
// 	i++;
// 	while (str[i] != '\0' && str[i] != 32 && str[i] != '\t')
// 	{
// 		(1==(write(1, &str[i], 1)));
// 		i++;
// 	}
// }
// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 		last_word(av[1]);
// 	(1==(write(1, "\n", 1)));
// }