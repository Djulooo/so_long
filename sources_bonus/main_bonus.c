/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:12 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/16 13:22:48 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*var;

	var = (t_game *)malloc(sizeof(t_game));
	if (var == NULL)
		display_error_malloc('m');
	if (argc == 2)
	{
		check_arg(argv[1]);
		init_struct(var, argv[1]);
		map_playable(var);
		mlx_hook(var->mlx_win, 2, 1L << 0, deal_key, var);
		mlx_hook(var->mlx_win, 17, 1L << 17, close_win, var);
		mlx_loop_hook(var->mlx_ptr, jim_position, var);
		mlx_loop(var->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}
