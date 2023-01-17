/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:59:38 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/15 14:54:53 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_error_non_rect(void)
{
	ft_putstr_fd("Error, the map is not a rectangle.\n", 1);
	exit(EXIT_FAILURE);
}

void	display_error_empty(int fd)
{
	if (fd == -1)
		ft_putstr_fd("Error fd.\n", 1);
	else
		ft_putstr_fd("Error, the map is empty.\n", 1);
	exit(EXIT_FAILURE);
}

void	display_error_malloc(char c)
{
	if (c == 'm')
		ft_putstr_fd("Error, memory was not allocated properly.\n", 1);
	else
		ft_putstr_fd("Error, the map is not winnable.\n", 1);
	exit(EXIT_FAILURE);
}

void	display_error_missing(void)
{
	ft_putstr_fd("Error, invalid parameters.\n", 1);
	exit(EXIT_FAILURE);
}

void	display_error_wall(char c)
{
	if (c != '1')
	{
		ft_putstr_fd("Error, the map is open.\n", 1);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}
