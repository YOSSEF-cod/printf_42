
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int ft_puthex_lowercase(unsigned long nbr);
int	ft_puthex_uppercas(unsigned long nbr);
int	ft_printaddress(void *ptr);
size_t	ft_strlen(const char*s);
int ft_putchar(char c);
int ft_putunsigned_int(unsigned int nbr);

#endif