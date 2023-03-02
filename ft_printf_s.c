/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:36:06 by adrgonza          #+#    #+#             */
/*   Updated: 2022/12/05 16:24:32 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	c;

	if (!s)
		return (write(1, "(null)", 6));
	c = 0;
	while (s[c])
		c++;
	return (write(1, s, c));
}

int	ft_putnbr(int nb)
{
	int	a;

	a = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		a += ft_putchr('-');
		nb = nb * -1;
	}
	if (nb > 9)
		a += ft_putnbr(nb / 10);
	return (a += ft_putchr(nb % 10 + '0'));
}

int	ft_check_conversions(char s, va_list args)
{
	if (s == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		a;

	va_start(args, s);
	a = 0;
	while (*s)
	{
		if (*s == '%')
			a += ft_check_conversions(*(++s), args);
		else
			a += write(1, &*s, 1);
		s++;
	}
	va_end(args);
	return (a);
}
