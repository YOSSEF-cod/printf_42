#include "ft_printf.h"

int ft_putunsigned_int(unsigned int nbr)
{
	char buffer[10];
	int i;

	i = 0;
	while (nbr)
	{
		buffer[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	while (i)
		ft_putchar(buffer[--i]);
	return 1;
}