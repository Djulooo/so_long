/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:21:52 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/16 13:53:10 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_struct(t_game *var, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		display_error_empty(fd);
	var->move = 1;
	var->map = parse_map(argv, fd);
	var->len = ft_strlen(var->map[0]) - 1;
	var->len *= 50;
	var->width = 0;
	while (var->map[var->width] != NULL)
		var->width++;
	var->width *= 50;
	var->pix_hei = 50;
	var->win_hei = 400;
	var->x = 0;
	var->y = 0;
	var->player_x = -1;
	var->player_y = -1;
	var->dead = 0;
	var->jim_pos = 0;
	var->exit_pos = 0;
	var->loop = 0;
	init_images(var);
}

void	init_images(t_game *var)
{
	var->mlx_ptr = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx_ptr, var->len, \
						var->width, "Danger in The Office");
	var->floor = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/floor.xpm", &var->pix_hei, &var->pix_hei);
	var->desk = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/desk.xpm", &var->pix_hei, &var->pix_hei);
	var->exit = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/exit.xpm", &var->pix_hei, &var->pix_hei);
	var->coll = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/collect.xpm", &var->pix_hei, &var->pix_hei);
	var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/player_r.xpm", &var->pix_hei, &var->pix_hei);
	var->jim = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/jim_r.xpm", &var->pix_hei, &var->pix_hei);
	var->pam = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/pam.xpm", &var->pix_hei, &var->pix_hei);
	var->success = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/promotion.xpm", &var->win_hei, &var->pix_hei);
	print_win(var);
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
	return (0);
}
