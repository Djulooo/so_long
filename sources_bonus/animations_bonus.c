/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:32:02 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/16 14:08:14 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	jim_update(t_game *var, int pos)
{
	if (pos == 0 || pos == 3)
	{
		var->jim = mlx_xpm_file_to_image(var->mlx_ptr, \
			"./assets/xpm/jim_l.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->jim)
			display_error_malloc('m');
	}
	else
	{
		var->jim = mlx_xpm_file_to_image(var->mlx_ptr, \
			"./assets/xpm/jim_r.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->jim)
			display_error_malloc('m');
	}
}

static void	new_jim(t_game *var, int i, int j)
{
	mlx_destroy_image(var->mlx_ptr, var->jim);
	if (var->jim_pos == 0)
	{
		jim_update(var, var->jim_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->jim, j * 50, i * 50);
		var->jim_pos++;
	}
	else if (var->jim_pos == 1)
	{
		jim_update(var, var->jim_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->jim, j * 50, i * 50);
		var->jim_pos++;
	}
	else
	{
		jim_update(var, var->jim_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->jim, j * 50, i * 50);
		var->jim_pos = 0;
	}
}

static void	exit_update(t_game *var, int pos)
{
	if (pos == 0 || pos == 3)
	{
		var->exit = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/exit_r.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->exit)
			display_error_malloc('m');
	}
	else
	{
		var->exit = mlx_xpm_file_to_image(var->mlx_ptr, \
				"./assets/xpm/exit.xpm", &var->pix_hei, &var->pix_hei);
		if (!var->exit)
			display_error_malloc('m');
	}
}

static void	new_exit(t_game *var, int i, int j)
{
	mlx_destroy_image(var->mlx_ptr, var->exit);
	if (var->exit_pos == 0)
	{
		exit_update(var, var->exit_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->exit, j * 50, i * 50);
		var->exit_pos++;
	}
	else if (var->exit_pos == 1)
	{
		exit_update(var, var->exit_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->exit, j * 50, i * 50);
		var->exit_pos++;
	}
	else
	{
		exit_update(var, var->exit_pos);
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->exit, j * 50, i * 50);
		var->exit_pos = 0;
	}
}

int	jim_position(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	if (var->loop < 10000)
	{
		var->loop++;
		return (0);
	}
	var->loop = 0;
	while (var->map[i])
	{
		j = 0;
		while (var->map[i][j])
		{
			if (var->map[i][j] == 'J')
				new_jim(var, i, j);
			if (var->map[i][j] == 'E')
				new_exit(var, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
