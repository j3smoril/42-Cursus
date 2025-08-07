/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:00:58 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:00:59 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->img_width, y * game->img_height);
}

void	char_render(t_game *game)
{
	ft_put_image(game, game->img_char, game->char_x, game->char_y);
}

void	ft_map_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				ft_put_image(game, game->img_wall, j, i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				ft_put_image(game, game->img_field, j, i);
			else if (game->map[i][j] == 'C')
				ft_put_image(game, game->img_collect, j, i);
			else if (game->map[i][j] == 'E')
				ft_put_image(game, game->img_exit, j, i);
			j++;
		}
		i++;
	}
}
