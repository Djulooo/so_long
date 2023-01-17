/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:12:30 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/15 16:40:51 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_left(t_game *var, char d)
{
	if (var->map[var->player_y][var->player_x] == 'E' &&
		var->collect == 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x + 1) * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->success, var->len / 2, var->width / 2 - 50);
		var->dead = 1;
	}
	else if (var->map[var->player_y][var->player_x] == '1' ||
		var->map[var->player_y][var->player_x] == 'E')
		var->player_x += 1;
	else
		move_left_else(var, d);
}

static void	move_right(t_game *var, char d)
{
	if (var->map[var->player_y][var->player_x] == 'E' &&
		var->collect == 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x - 1) * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->success, var->len / 2, var->width / 2 - 50);
		var->dead = 1;
	}
	else if (var->map[var->player_y][var->player_x] == '1' ||
		var->map[var->player_y][var->player_x] == 'E')
		var->player_x -= 1;
	else
		move_right_else(var, d);
}

static void	move_up(t_game *var, char d)
{
	if (var->map[var->player_y][var->player_x] == 'E' &&
		var->collect == 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, var->player_x * 50, (var->player_y + 1) * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->success, var->len / 2, var->width / 2 - 50);
		var->dead = 1;
	}
	else if (var->map[var->player_y][var->player_x] == '1' ||
		var->map[var->player_y][var->player_x] == 'E')
		var->player_y += 1;
	else
		move_up_else(var, d);
}

static void	move_down(t_game *var, char d)
{
	if (var->map[var->player_y][var->player_x] == 'E' &&
			var->collect == 0)
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, var->player_x * 50, (var->player_y - 1) * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->success, var->len / 2, var->width / 2 - 50);
		var->dead = 1;
	}
	else if (var->map[var->player_y][var->player_x] == '1' ||
		var->map[var->player_y][var->player_x] == 'E')
		var->player_y -= 1;
	else
		move_down_else(var, d);
}

void	move_instr(int key, t_game *var)
{
	if (key == 13)
	{
		var->player_y -= 1;
		move_up(var, 'w');
	}
	else if (key == 0)
	{
		var->player_x -= 1;
		move_left(var, 'a');
	}
	else if (key == 1)
	{
		var->player_y += 1;
		move_down(var, 's');
	}
	else if (key == 2)
	{
		var->player_x += 1;
		move_right(var, 'd');
	}
	put_string(var);
}
