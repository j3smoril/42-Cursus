/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:27:25 by jesmoril          #+#    #+#             */
/*   Updated: 2024/10/23 12:27:27 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long num, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (num >= (unsigned long)base_len)
		len += ft_putnbr_base(num / base_len, base);
	len += ft_putchar (base[num % base_len]);
	return (len);
}
