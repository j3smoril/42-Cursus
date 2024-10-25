/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:09:33 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/24 19:09:40 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*sp1;
	char	*sp2;

	i = 0;
	sp1 = (char *)s1;
	sp2 = (char *)s2;
	while (i < n)
	{
		if ((unsigned char)sp1[i] != (unsigned char)sp2[i])
			return ((unsigned char)sp1[i] - (unsigned char)sp2[i]);
		i++;
	}
	return (0);
}
