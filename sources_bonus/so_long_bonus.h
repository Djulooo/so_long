/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:13:59 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 18:02:30 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*pam;
	void	*jim;
	void	*success;
	int		dead;
	int		collect;
	int		move;
	int		pix_hei;
	int		win_hei;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		temp_e;
	int		temp_c;
	int		loop;
	int		jim_pos;
	int		exit_pos;
	size_t	width;
	size_t	len;
}	t_game;

/* --- error messages */
void	display_error_non_rect(void);
void	display_error_empty(int fd);
void	display_error_malloc(char c);
void	display_error_missing(void);
void	display_error_wall(char c);

/* --- parse map --- */
void	check_arg(char *arg);
void	error_param(char **map);
void	error_ext_walls(char **map);
void	free_map(char **map);
char	**parse_map(char *str, int fd);

void	put_image(char c, t_game *var);
int		print_win(t_game *var);
void	player_image(char collect, char key, t_game *var);
int		jim_position(t_game *var);

int		put_string(t_game *var);
void	player_death(t_game *var, char d);

void	move_left_else(t_game *var, char d);
void	move_right_else(t_game *var, char d);
void	move_up_else(t_game *var, char d);
void	move_down_else(t_game *var, char d);

void	init_images(t_game *var);
void	init_struct(t_game *var, char *argv);

int		close_win(t_game *var);
void	move_instr(int key, t_game *var);
int		deal_key(int key, t_game *var);

/*	path_finding	*/
int		count_c(char **tab);
int		count_e(char **tab);
void	copy_map(char **tab, t_game *var);
int		map_playable(t_game *var);

#endif