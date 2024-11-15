#include "ft_printf.h"

static int check_character(const char *str, va_list args)
{
    int i = 0;
    int res = 0;

    while (str[i])
    {
        if (str[i] == 's')
            res += ft_putstr(va_arg(args, char *));
        else if (str[i] == 'd' || str[i] == 'i')
            res += ft_putnbr(va_arg(args, int));
         else if (str[i] == 'c')
            res += ft_putchar(va_arg(args, int));
        else if (str[i] == 'u')
            res += ft_putunsigned_int(va_arg(args, unsigned long));
        else if (str[i] == 'p')
            res += ft_printaddress(va_arg(args, void *));
        else if (str[i] == 'X')
            res += ft_puthex_uppercas(va_arg(args, unsigned long));
        else if (str[i] == 'x')
            res += ft_puthex_lowercase(va_arg(args, unsigned long));
        i++;
    }
    return res;
}

int ft_printf(const char *format, ...)
{
	int i;
    int res;

	i = 0;
    res = 0;
	va_list(list);
	va_start(list, format);
	if (!format && write(1, 0, 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{ 
			res += check_character(&format[++i], list);
		}
			res += ft_putchar(format[i]);
		i++; 
	}
	va_end(list);
	return res;
}
