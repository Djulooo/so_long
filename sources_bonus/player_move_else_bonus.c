/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_else_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:10:55 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/15 16:18:44 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left_else(t_game *var, char d)
{
	player_image(var->map[var->player_y][var->player_x], d, var);
	if (var->map[var->player_y][var->player_x] == 'C')
	{
		var->collect--;
		var->map[var->player_y][var->player_x] = '0';
	}
	if (var->map[var->player_y][var->player_x] == 'J')
		player_death(var, d);
	else
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->player, var->player_x * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x + 1) * 50, (var->player_y) * 50);
	}
}

void	move_right_else(t_game *var, char d)
{
	player_image(var->map[var->player_y][var->player_x], d, var);
	if (var->map[var->player_y][var->player_x] == 'C')
	{
		var->collect--;
		var->map[var->player_y][var->player_x] = '0';
	}
	if (var->map[var->player_y][var->player_x] == 'J')
		player_death(var, d);
	else
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->player, var->player_x * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x - 1) * 50, (var->player_y) * 50);
	}
}

void	move_up_else(t_game *var, char d)
{
	player_image(var->map[var->player_y][var->player_x], d, var);
	if (var->map[var->player_y][var->player_x] == 'C')
	{
		var->collect--;
		var->map[var->player_y][var->player_x] = '0';
	}
	if (var->map[var->player_y][var->player_x] == 'J')
		player_death(var, d);
	else
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->player, var->player_x * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x) * 50, (var->player_y + 1) * 50);
	}
}

void	move_down_else(t_game *var, char d)
{
	player_image(var->map[var->player_y][var->player_x], d, var);
	if (var->map[var->player_y][var->player_x] == 'C')
	{
		var->collect--;
		var->map[var->player_y][var->player_x] = '0';
	}
	if (var->map[var->player_y][var->player_x] == 'J')
		player_death(var, d);
	else
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->player, var->player_x * 50, var->player_y * 50);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->floor, (var->player_x) * 50, (var->player_y - 1) * 50);
	}
}
