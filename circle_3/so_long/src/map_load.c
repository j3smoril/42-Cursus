/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:00:45 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:00:47 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "\033[1;31mError\033[0m Map no exist.\n", 32);
		free(game);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	game->height = 0;
	while (line != NULL)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(fd);
	free(line);
	close(fd);
}

void	ft_load_map(t_game *game)
{
	int		i;
	size_t	len;
	int		fd;
	char	*line;

	i = 0;
	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		ft_free(game);
	line = get_next_line(fd);
	game->map = malloc(sizeof(char *) * game->height);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		game->map[i] = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(game->map[i], line, len + 1);
		game->map[i][len] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
}
