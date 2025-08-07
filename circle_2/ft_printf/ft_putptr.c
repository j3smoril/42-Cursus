/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:28:04 by jesmoril          #+#    #+#             */
/*   Updated: 2024/10/23 12:28:06 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_putstr ("(nil)");
	else
	{
		len += ft_putstr ("0x");
		len += ft_putnbr_base ((unsigned long)ptr, "0123456789abcdef");
	}
	return (len);
}
