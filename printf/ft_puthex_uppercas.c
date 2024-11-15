#include "ft_printf.h"

int	ft_puthex_uppercas(unsigned long nbr)
{
	char *str;
	int res;

	res = 0;
	str = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthex_uppercas(nbr / 16);
	else
		res = ft_putchar(str[nbr % 16]);
	return res;
}