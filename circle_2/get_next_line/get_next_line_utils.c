/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:44:24 by jesmoril          #+#    #+#             */
/*   Updated: 2024/12/27 17:44:26 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoinfree(char *storage, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage || !buffer)
		return (NULL);
	str = malloc ((ft_strlen(storage) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (storage[i])
	{
		str[i] = storage[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	free (storage);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)str + i);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = malloc (nmemb * size);
	if (ptr == NULL)
		return (0);
	while (i != n)
	{
		((unsigned char *)ptr)[i++] = 0;
	}
	return (ptr);
}
