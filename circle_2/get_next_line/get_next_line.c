/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:24 by jesmoril          #+#    #+#             */
/*   Updated: 2024/12/27 17:42:34 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *storage)
{
	int		len_read;
	char	*buffer;

	len_read = 1;
	if (!storage)
		storage = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (len_read > 0 && !ft_strchr(storage, '\n'))
	{
		len_read = read (fd, buffer, BUFFER_SIZE);
		if (len_read == -1)
		{
			free (storage);
			free (buffer);
			return (0);
		}
		buffer[len_read] = '\0';
		storage = ft_strjoinfree(storage, buffer);
	}
	free (buffer);
	return (storage);
}

char	*ft_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (0);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!buffer)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	buffer[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	storage = ft_read_file(fd, storage);
	if (!storage)
		return (0);
	line = ft_line (storage);
	storage = ft_save (storage);
	return (line);
}
