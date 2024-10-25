/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:13:22 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/29 17:13:24 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*ptr;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc(s1len + s2len + 1);
	if (!s1 || !s2 || !ptr)
		return (0);
	while (s1len--)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2len--)
	{
		ptr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
