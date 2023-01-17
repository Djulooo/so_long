/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:18:32 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 18:05:00 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_param(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			display_error_wall(map[i][j]);
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'P')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 2)
		display_error_missing();
}

void	error_ext_walls(char **map)
{
	int	i;

	i = 1;
	while (map[i] && map[i + 1])
	{
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			display_error_wall(map[i][ft_strlen(map[i]) - 2]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return ;
}
