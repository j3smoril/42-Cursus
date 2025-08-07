/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:37:48 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/30 14:37:49 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	int			ptrlen;
	char		*ptr;
	long int	nbr;

	nbr = n;
	ptrlen = ft_numlen(n, 10);
	ptr = malloc((ptrlen + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[ptrlen] = 0;
	i = ptrlen - 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ptr[0] = '-';
	}
	while (nbr > 9)
	{
		ptr[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	ptr[i] = nbr + '0';
	return (ptr);
}
