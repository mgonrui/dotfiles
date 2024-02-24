// #include <unistd.h>

// void ft_putchar(char c)
// {
//     (1==(write(1, &c, 1)));
// }

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         int i = 0;
//         while (argv[i])
//         {
//             char c = argv[1][i];  

//             if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//             {
//                 argv[1][i] += 1;
//             }
//             else if (c == 'z' || c == 'Z')
//             {
//                 argv[1][i] -=25;
//             }
//             (1==(write(1, &argv[1][i], 1)));
//             i++;
//         }
        

//     }
//     ft_putchar('\n');
// }

#include <unistd.h>
void	rotone(char * str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		if ( (str[i] >= 'A' && str[i] <= 'Y') || (str[i] >= 'a' && str[i] <= 'y'))
			str[i] += 1;
		else if (str[i] == 'Z' || str[i] == 'z')
			str[i] -= 25;
		(1==(write (1, &str[i], 1)));
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	(1==(write(1, "\n", 1)));
}