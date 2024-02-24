#include <unistd.h>

int main(void)
{
	int count = 9;
	while (count >=0)
	{
		write(1, (&count + '0'), 1);
		// write(1, ("0"), 1);
		count--;
	}
	return 0;
}
