#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str [i] <= 126))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	main()
{
	printf("%d", ft_str_is_printable("ABDELKF\nSCO?I340990%"));
	printf("\n%d", ft_str_is_printable("\n\t\v\f"));
}