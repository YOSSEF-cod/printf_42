#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	int i;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		i = ft_putchar('-');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		i = ft_putchar(nbr % 10 + 48);
	}
	else
		i = ft_putchar(nbr + 48);
	return i;
}
