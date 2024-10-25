/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:59:12 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/24 18:59:14 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (0);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i != n)
	{
		d[i] = s[i];
		i ++;
	}
	return (dest);
}
