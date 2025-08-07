/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:01:06 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:01:07 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_game *game)
{
	if (key == 65307)
	{
		ft_free(game);
	}
	else if (key == 119 || key == 65362)
		ft_move(game, 0, -1);
	else if (key == 115 || key == 65364)
		ft_move(game, 0, 1);
	else if (key == 97 || key == 65361)
		ft_move(game, -1, 0);
	else if (key == 100 || key == 65363)
		ft_move(game, 1, 0);
	return (0);
}

void	ft_move(t_game *game, int x, int y)
{
	if (game->map[game->char_y + y][game->char_x + x] != '1')
	{
		game->char_x += x;
		game->char_y += y;
		if (game->map[game->char_y][game->char_x] == 'C')
		{
			game->c_count--;
			game->map[game->char_y][game->char_x] = '0';
		}
		game->step++;
		write(1, "Steps: ", 8);
		ft_putnbr_fd(game->step, 1);
		write(1, "\n", 1);
	}
	if (game->map[game->char_y][game->char_x] == 'E' && game->c_count == 0)
	{
		write(1, "You win! Total steps: ", 22);
		ft_putnbr_fd(game->step, 1);
		write(1, "\n", 1);
		ft_free(game);
		exit(0);
	}
}
