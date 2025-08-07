/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:00:33 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:00:34 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_input(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E')
			{
				write(1, "\033[1;31mError\033[0m ", 18);
				write(1, "Incorrect Input. Use 1 0 P E C\n", 32);
				ft_free(game);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_map_close(t_game *game)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(1, "\033[1;31mError\033[0m Map is no close.\n", 35);
		ft_free(game);
		exit (EXIT_FAILURE);
	}
}

void	ft_map_items(t_game *game)
{
	if (game->p_count != 1)
	{
		write(1, "\033[1;31mError\033[0m Player number is incorrect.\n", 46);
		ft_free(game);
		exit (EXIT_FAILURE);
	}
	if (game->c_count < 1)
	{
		write(1, "\033[1;31mError\033[0m Map no have collectible.\n", 43);
		ft_free(game);
		exit (EXIT_FAILURE);
	}
	if (game->e_count != 1)
	{
		write(1, "\033[1;31mError\033[0m Map have only one exit.\n", 42);
		ft_free(game);
		exit (EXIT_FAILURE);
	}
}

void	ft_map_rect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		ft_strlen(game->map[i]);
		if ((int)ft_strlen(game->map[i]) != game->width)
		{
			write(1, "\033[1;31mError\033[0m Map is no rec.\n", 33);
			ft_free(game);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_check_solvable(t_game *game, int x, int y, int valid)
{
	char	pos;

	pos = game->map[y][x];
	if (pos != '1' && pos != 'T')
	{
		if (pos == 'E')
			valid = 1;
		if (pos == 'C')
			game->c_solved++;
		game->map[y][x] = 'T';
		if (x + 1 < game->width)
			ft_check_solvable(game, x + 1, y, valid);
		if (x - 1 >= 0)
			ft_check_solvable(game, x - 1, y, valid);
		if (y + 1 < game->height)
			ft_check_solvable(game, x, y + 1, valid);
		if (y - 1 >= 0)
			ft_check_solvable(game, x, y - 1, valid);
	}
	return (valid);
}
