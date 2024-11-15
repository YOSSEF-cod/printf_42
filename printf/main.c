
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
static int ft_puthex_lowercase(unsigned long n);
static int ft_puthex_uppercase(unsigned long n);
static int ft_putnbr(int n);
static int ft_putunsigned(unsigned long n);
static int ft_putstr(char *str);
static int ft_putchar(char c);
static int check_character(const char *str, va_list list);

static int ft_puthex_lowercase(unsigned long n)
{
    char hex[] = "0123456789abcdef";
    int res = 0;

    if (n >= 16)
        res += ft_puthex_lowercase(n / 16);
    res += ft_putchar(hex[n % 16]);
    return res;
}

static int ft_puthex_uppercase(unsigned long n)
{
    char hex[] = "0123456789ABCDEF";
    int res = 0;

    if (n >= 16)
        res += ft_puthex_uppercase(n / 16);
    res += ft_putchar(hex[n % 16]);
    return res;
}

static int ft_putnbr(int n)
{
    int res = 0;
    if (n == -2147483648) // handle INT_MIN
    {
        res += ft_putchar('-');
        res += ft_putchar('2');
        n = 147483648;
    }
    if (n < 0)
    {
        res += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        res += ft_putnbr(n / 10);
    res += ft_putchar(n % 10 + '0');
    return res;
}

static int ft_putunsigned(unsigned long n)
{
    int res = 0;
    if (n >= 10)
        res += ft_putunsigned(n / 10);
    res += ft_putchar(n % 10 + '0');
    return res;
}

static int ft_putstr(char *str)
{
    int res = 0;
    while (*str)
    {
        res += ft_putchar(*str);
        str++;
    }
    return res;
}

static int ft_putchar(char c)
{
    return write(1, &c, 1);
}

static int check_character(const char *str, va_list list)
{
    int res = 0;
    if (*str == 's') {
        res += ft_putstr(va_arg(list, char *));
    }
    else if (*str == 'c') {
        res += ft_putchar(va_arg(list, int));
    }
    else if (*str == 'p') {
        res += ft_putstr("0x");
        res += ft_puthex_lowercase((unsigned long) va_arg(list, void *));
    }
    else if (*str == 'd' || *str == 'i') {
        res += ft_putnbr(va_arg(list, int));
    }
    else if (*str == 'x') {
        res += ft_puthex_lowercase(va_arg(list, unsigned long));
    }
    else if (*str == 'X') {
        res += ft_puthex_uppercase(va_arg(list, unsigned long));
    }
    else if (*str == 'u') {
        res += ft_putunsigned(va_arg(list, unsigned long));
    }
    return res;
}

int ft_printf(const char *format, ...)
{
    int i = 0;
    int b = 0;
    va_list list;

    va_start(list, format);

    // Check if the format is NULL
    if (!format) {
        va_end(list);
        return -1;
    }

    while (format[i]) {
        if (format[i] == '%') {
            i++;
            b += check_character(&format[i], list);
        }
        else {
            b += ft_putchar(format[i]);
        }
        i++;
    }

    va_end(list);
    return b;
}
int main()
{
  ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
}
