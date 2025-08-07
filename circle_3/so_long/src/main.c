/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:00:23 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 18:00:24 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		write(1, "\033[1;31mError\033[0m  Use ./so_long name.ber\n", 42);
		return (0);
	}
	if (ft_strlen(av[1]) <= 4
		|| ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
	{
		write (1, "\033[1;31mError\033[0m  Use .ber extension\n", 38);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	ft_game_init(game, av[1]);
}
