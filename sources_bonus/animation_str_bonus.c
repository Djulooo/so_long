/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:55:27 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/16 13:55:42 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_string(t_game *var)
{
	char	*move;

	move = ft_itoa(var->move);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->desk, 0, 0);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->desk, 50, 0);
	mlx_string_put(var->mlx_ptr, var->mlx_win, 0, 0, 0x000000, "Move: ");
	mlx_string_put(var->mlx_ptr, var->mlx_win, 50, 0, 0x000000, move);
	free(move);
	var->move++;
	return (0);
}

void	player_death(t_game *var, char d)
{
	if (d == 's')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->pam, (var->player_x) * 50, (var->player_y - 1) * 50);
	else if (d == 'd')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->pam, (var->player_x - 1) * 50, (var->player_y) * 50);
	else if (d == 'a')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->pam, (var->player_x + 1) * 50, (var->player_y) * 50);
	else if (d == 'w')
		mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, \
				var->pam, (var->player_x) * 50, (var->player_y + 1) * 50);
	var->dead = 1;
}
