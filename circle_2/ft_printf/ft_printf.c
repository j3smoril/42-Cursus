/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:18:10 by jesmoril          #+#    #+#             */
/*   Updated: 2024/10/22 17:18:20 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_puthex_l(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_puthex_u(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += ft_case(format[++i], args);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}
