/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:00:11 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:00:13 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loop(t_game *game)
{
	ft_map_render(game);
	char_render(game);
	return (0);
}

void	ft_load_sprites(t_game *game)
{
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_field = mlx_xpm_file_to_image(game->mlx, "sprites/field.xpm",
			&game->img_width, &game->img_height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "sprites/collect.xpm",
			&game->img_width, &game->img_height);
	game->img_char = mlx_xpm_file_to_image(game->mlx, "sprites/char.xpm",
			&game->img_width, &game->img_height);
}

void	ft_load_data(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P' )
			{
				game->p_count++;
				game->char_x = j;
				game->char_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->c_count++;
			else if (game->map[i][j] == 'E')
				game->e_count++;
			j++;
		}
		i++;
	}
}

void	ft_game_init(t_game *game, char *av)
{
	game->img_height = 32;
	game->img_width = 32;
	game->char_x = 0;
	game->char_y = 0;
	game->step = 0;
	game->c_count = 0;
	game->p_count = 0;
	game->e_count = 0;
	game->c_solved = 0;
	game->map_path = av;
	game->map = NULL;
	ft_game_load(game);
}

void	ft_game_load(t_game *game)
{
	ft_map_size(game);
	ft_load_map(game);
	ft_load_data(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * game->img_width,
			game->height * game->img_height, "so_long");
	ft_load_sprites(game);
	ft_map_check(game);
	mlx_hook(game->win, 17, 0, ft_free, game);
	mlx_key_hook(game->win, ft_key, game);
	mlx_loop_hook(game->mlx, ft_loop, game);
	mlx_loop(game->mlx);
}
