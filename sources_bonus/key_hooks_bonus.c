/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:14:30 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/01/15 16:33:57 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_game *var)
{
	free_map(var->map);
	mlx_destroy_image(var->mlx_ptr, var->player);
	mlx_destroy_image(var->mlx_ptr, var->floor);
	mlx_destroy_image(var->mlx_ptr, var->desk);
	mlx_destroy_image(var->mlx_ptr, var->exit);
	mlx_destroy_image(var->mlx_ptr, var->coll);
	mlx_clear_window(var->mlx_ptr, var->mlx_win);
	mlx_destroy_window(var->mlx_ptr, var->mlx_win);
	free(var->mlx_ptr);
	exit (EXIT_SUCCESS);
}

int	deal_key(int key, t_game *var)
{
	if (key == 53)
		close_win(var);
	else if ((key == 13 || key == 0 || key == 1 || key == 2)
		&& var->dead != 1)
		move_instr(key, var);
	return (0);
}
