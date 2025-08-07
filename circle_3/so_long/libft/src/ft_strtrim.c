/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:07:26 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/29 19:07:27 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_checkset(set, s1[start]))
		start++;
	while (ft_checkset(set, s1[end]))
		end--;
	len = end - (start -1);
	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + start, len + 1);
	return (ptr);
}
