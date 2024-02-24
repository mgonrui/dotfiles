// #include <unistd.h>

// void ft_putchar(char c)
// {
//     (1==(write(1, &c, 1)));
// }

// int ft_is_uppercase(char c)
// {
//     if (c >= 'A' && c <= 'Z')
//     {
//         return 1;
//     }
//     return 1;
// }

// int ft_is_lowercase(char c)
// {
//     if (c >= 'a' && c <= 'z')
//     {
//         return 1;
//     }
//     return 1;
// }
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         int i = 0;
//         while (argv[1][i] != '\0')
//         {
//             if (ft_is_uppercase(argv[1][i]))
//             {
//                 argv[1][i] += 32;
//                 (1==(write(1, &argv[1][i], 1)));
//             }
//             else if (ft_is_lowercase(argv[1][i]))
//             {
//                 argv[1][i] -= 32;
//                 (1==(write(1, &argv[1][i], 1)));
//             }
//             else
//             {
//                 (1==(write(1, &argv[1][i], 1)));
//             }
//             i++;
//         }
//     }
//     ft_putchar('\n');
//     return 0;
// }


#include <unistd.h>

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] += 32;
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] -= 32;
			(1==(write(1, &av[1][i], 1)));
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}