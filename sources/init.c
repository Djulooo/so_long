/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:21:52 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/16 10:26:25 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image_bis(t_game *var)
{
	var->exit = mlx_xpm_file_to_image(var->mlx_ptr, \
			"./assets/xpm/exit.xpm", &var->pix_hei, &var->pix_hei);
	if (!var->exit)
		display_error_malloc('m');
	var->coll = mlx_xpm_file_to_image(var->mlx_ptr, \
			"./assets/xpm/collect.xpm", &var->pix_hei, &var->pix_hei);
	if (!var->coll)
		display_error_malloc('m');
	var->player = mlx_xpm_file_to_image(var->mlx_ptr, \
			"./assets/xpm/player_r.xpm", &var->pix_hei, &var->pix_hei);
	if (!var->player)
		display_error_malloc('m');
}

static void	init_images(t_game *var)
{
	var->mlx_ptr = mlx_init();
	if (!var->mlx_ptr)
		display_error_malloc('m');
	var->mlx_win = mlx_new_window(var->mlx_ptr, var->len, \
					var->width, "Danger in The Office");
	var->floor = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/floor.xpm", &var->pix_hei, &var->pix_hei);
	if (!var->floor)
		display_error_malloc('m');
	var->desk = mlx_xpm_file_to_image(var->mlx_ptr, \
					"./assets/xpm/desk.xpm", &var->pix_hei, &var->pix_hei);
	if (!var->desk)
		display_error_malloc('m');
	init_image_bis(var);
	print_win(var);
}

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
	var->x = 0;
	var->y = 0;
	var->player_x = -1;
	var->player_y = -1;
	var->dead = 0;
	init_images(var);
}
