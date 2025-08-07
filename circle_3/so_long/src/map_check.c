/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:48:14 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/30 18:48:15 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_game *game)
{
	int	sol;

	ft_map_rect(game);
	ft_map_items(game);
	ft_map_input(game);
	ft_map_close(game);
	sol = ft_check_solvable(game, game->char_x, game->char_y, 0);
	if (sol || game->c_solved != game->c_count)
	{
		write(1, "\033[1;31mError\033[0m Map is not solvable.\n", 39);
		ft_free(game);
		exit(EXIT_FAILURE);
	}
	ft_free_map(game);
	ft_load_map(game);
}
