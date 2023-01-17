/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:32:38 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/01/16 10:23:01 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_image_thrid(char collect, char key, t_game *var)
{
	if (key == 'a' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/player_l.xpm", &var->pix_hei, &var->pix_hei);
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
	else if (key == 'd' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/player_rc.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
}

static void	player_image_bis(char collect, char key, t_game *var)
{
	if (key == 's' && collect != 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/player_l.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->player)
			display_error_malloc('m');
	}
	else if (key == 's' && collect == 'C')
	{
		var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/player_lc.xpm", &var->pix_hei, &var->pix_hei);
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
	player_image_thrid(collect, key, var);
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
	player_image_bis(collect, key, var);
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
	else if (c == '1')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->desk, var->x, var->y);
}

int	print_win(t_game *var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	var->collect = 0;
	while (var->map[i])
	{
		while (var->map[i][j])
		{
			put_image(var->map[i][j], var);
			var->x += 50;
			j++;
		}
		j = 0;
		var->x = 0;
		var->y += 50;
		i++;
	}
	if (var->collect == 0)
		display_error_missing();
	return (0);
}
