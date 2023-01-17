/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:32:38 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/01/15 17:06:53 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_image_third(t_game *var, char collect, char key)
{
	if (key == 's' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_l.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 'd' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_r.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
}

static void	player_image_bis(t_game *var, char collect, char key)
{
	if (key == 's' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_lc.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 'd' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_rc.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 'a' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_lc.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	player_image_third(var, collect, key);
}

void	player_image(char collect, char key, t_game *var)
{
	mlx_destroy_image(var->mlx_ptr, var->player);
	if (key == 'w' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_r.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 'w' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_rc.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 'a' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_l.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	player_image_bis(var, collect, key);
}

static void	put_image_else(char c, t_game *var)
{
	if (c == '1')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->desk, var->x, var->y);
	else if (c == 'J')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->jim, var->x, var->y);
}

void	put_image(char c, t_game *var)
{
	if (c == '0')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->floor, var->x, var->y);
	else if (c == 'E')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->exit, var->x, var->y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->coll, var->x, var->y);
		var->collect++;
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
					var->player, var->x, var->y);
		if (var->player_x == -1 && var->player_y == -1)
		{
			var->player_x = var->x / 50;
			var->player_y = var->y / 50;
		}
	}
	put_image_else(c, var);
}
