#include "ft_printf.h"

int ft_putchar(char c)
{
	int i;

	i = write(1, &c, 1);
	return i;
}