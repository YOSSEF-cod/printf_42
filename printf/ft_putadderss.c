#include "ft_printf.h"

int	ft_printaddress(void *ptr)
{
	unsigned long	adres;
	int i;

	i = 0;
	adres = (unsigned long)ptr;
	i = ft_putstr("0x");
	if (adres == 0)
	{
		i += ft_putchar('0');
	}
	else 
		i += ft_puthex_lowercase(adres);
	return i;
}
