/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:59:40 by jesmoril          #+#    #+#             */
/*   Updated: 2025/07/28 17:59:55 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	char			**map;
	char			*map_path;		
	int				char_x;
	int				char_y;
	int				step;
	int				c_solved;

	int				c_count;
	int				p_count;
	int				e_count;

	int				img_height;
	int				img_width;

	void			*img_wall;
	void			*img_field;
	void			*img_collect;
	void			*img_char;
	void			*img_exit;

}	t_game;

void	ft_game_init(t_game *game, char *av);
void	ft_load_data(t_game *game);
void	ft_game_load(t_game *game);
void	ft_load_sprites(t_game *game);
int		ft_loop(t_game *game);

void	ft_map_size(t_game *game);
void	ft_load_map(t_game *game);

void	ft_put_image(t_game *game, void *img, int x, int y);
void	char_render(t_game *game);
void	ft_map_render(t_game *game);

void	ft_map_check(t_game *game);
void	ft_map_input(t_game *game);
void	ft_map_close(t_game *game);
void	ft_map_items(t_game *game);
void	ft_map_rect(t_game *game);
int		ft_check_solvable(t_game *game, int x, int y, int valid);

int		ft_free(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_sprites(t_game *game);

int		ft_key(int key, t_game *game);
void	ft_move(t_game *game, int x, int y);

#endif
