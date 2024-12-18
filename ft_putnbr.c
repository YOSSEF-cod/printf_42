/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:17:58 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:20:58 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int res;

	res = 0;
	if (n == -2147483648)
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
 