#include <unistd.h>

int main(void)
{
	char count = '9';
	while (count >='0')
	{
		write(1, &count, 1);
		count--;
	}
	write(1, "\n", 1);
	return 0;
}
