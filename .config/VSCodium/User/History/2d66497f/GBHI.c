#include <stdio.h>

void	ft_swap(int a, int b)
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int	main()
{
	int	x;
	int	y;
	
	x = 2;
	y = 3;
	ft_swap(x, y);
	printf(" x is %d \n", x);
	printf(" y is %d\n", y);
}