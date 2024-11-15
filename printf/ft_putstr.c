#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int i;

	i = write(1, str, ft_strlen(str));
	return i;
}