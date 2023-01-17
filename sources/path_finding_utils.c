/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:09:54 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 15:05:35 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	count_e(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 'E')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	copy_map(char **tab, t_game *var)
{
	size_t	i;

	i = 0;
	while (i < (var->width / 50))
	{
		tab[i] = ft_strdup(var->map[i]);
		i++;
	}
	tab[i] = NULL;
}
