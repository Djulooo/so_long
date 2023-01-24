/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:51:49 by juleslaisne       #+#    #+#             */
/*   Updated: 2023/01/24 11:10:53 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_backtrack(char **tab, t_game *var, int x, int y)
{
	if (tab[y][x] == 'C')
		var->temp_c--;
	tab[y][x] = '1';
}

static void	path_finding(char **tab, t_game *var, int x, int y)
{
	update_backtrack(tab, var, x, y);
	if (tab[y][x + 1] != '1' && tab[y][x + 1] != 'E')
		path_finding(tab, var, x + 1, y);
	if (tab[y][x + 1] == 'E')
		var->temp_e--;
	if (tab[y - 1][x] != '1' && tab[y - 1][x] != 'E')
		path_finding(tab, var, x, y - 1);
	if (tab[y - 1][x] == 'E')
		var->temp_e--;
	if (tab[y][x - 1] != '1' && tab[y][x - 1] != 'E')
		path_finding(tab, var, x - 1, y);
	if (tab[y + 1][x] == 'E')
		var->temp_e--;
	if (tab[y + 1][x] != '1' && tab[y][x - 1] != 'E')
		path_finding(tab, var, x, y + 1);
	if (tab[y][x - 1] == 'E')
		var->temp_e--;
}

int	map_playable(t_game *var)
{
	char	**tab;
	
	tab = malloc(sizeof(char *) * ((var->width / 50) + 1));
	if (!tab)
		display_error_malloc('m');
	copy_map(tab, var);
	var->temp_c = count_c(tab);
	var->temp_e = count_e(tab);
	path_finding(tab, var, var->player_x, var->player_y);
	if (var->temp_c <= 0 && var->temp_e <= 0)
		return (free_map(tab), 1);
	else
	{
		free_map(tab);
		display_error_malloc('a');
		return (0);
	}
}
