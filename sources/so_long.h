/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:13:59 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 15:16:19 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"

typedef struct s_game
{
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*floor;
	void	*desk;
	void	*exit;
	void	*coll;
	void	*player;
	int		collect;
	int		move;
	int		pix_hei;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		dead;
	int		temp_c;
	int		temp_e;
	size_t	width;
	size_t	len;
}	t_game;

/*		error messages		*/
void	display_error_non_rect(void);
void	display_error_empty(int fd);
void	display_error_malloc(char c);
void	display_error_missing(void);
void	display_error_wall(char c);

/*		parse map		*/
void	check_arg(char *arg);
void	error_param(char **map);
void	error_ext_walls(char **map);
void	free_map(char **map);
char	**parse_map(char *str, int fd);

/*		display map		*/
int		print_win(t_game *var);
void	put_image(char c, t_game *var);
void	player_image(char collect, char key, t_game *var);

/*		player movements		*/
void	move_right(t_game *var, char d);
void	move_left(t_game *var, char d);
void	move_up(t_game *var, char d);
void	move_down(t_game *var, char d);

/*		init struct			*/
void	init_struct(t_game *var, char *argv);

/*		keyhooks		*/
int		close_win(t_game *var);
void	move_instr(int key, t_game *var);
int		deal_key(int key, t_game *var);

/*	path_finding	*/
int		count_e(char **tab);
int		count_c(char **tab);
void	copy_map(char **tab, t_game *var);
int		map_playable(t_game *var);

#endif