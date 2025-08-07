/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:09:53 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/24 19:10:01 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (find[0] == 0)
		return ((char *) str);
	while (str[i] && i < len)
	{
		while (str[i + j] == find[j] && str[i + j] && i + j < len)
		{
			j++;
			if (find[j] == 0)
				return ((char *) str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
