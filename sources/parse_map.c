/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:04:33 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 18:12:06 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(char *arg)
{
	unsigned int	i;
	unsigned int	j;
	char			*needle;

	i = 0;
	j = 0;
	needle = ft_strdup(".ber");
	if (arg == NULL)
		exit(EXIT_FAILURE);
	while (arg[i] != '\0')
	{
		if (arg[i] == needle[0] && i >= 1)
		{
			j = 0;
			while (needle[j] && (arg[i + j] == needle[j]))
				j++;
			if (needle[j] == '\0' && arg[i + j] == '\0')
			{
				free(needle);
				return ;
			}
		}
		i++;
	}
	exit(EXIT_FAILURE);
}

static void	check_map_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			display_error_wall(map[0][i]);
		i++;
	}
	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			display_error_wall(map[i - 1][j]);
		j++;
	}
	error_ext_walls(map);
}

static void	check_map_param(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			display_error_wall(map[i][j]);
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P' \
				|| map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'J')
				j++;
			else
				display_error_missing();
		}
		j = 0;
		i++;
	}
	error_param(map);
}

static void	fill_map(char **map, char *str, size_t i, size_t len)
{
	int		fd;
	size_t	wid;

	wid = 0;
	fd = open(str, O_RDONLY);
	while (wid < i - 1)
	{
		map[wid] = get_next_line(fd);
		if (ft_strlen(map[wid]) != len)
			display_error_non_rect();
		wid++;
	}
	map[wid] = get_next_line(fd);
	if (ft_strlen(map[wid]) != len - 1)
		display_error_non_rect();
	map[wid + 1] = NULL;
	close (fd);
	check_map_param(map);
	check_map_wall(map);
}

char	**parse_map(char *str, int fd)
{
	size_t		i;
	size_t		str_len;
	char		*line;
	char		**map;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		display_error_empty(fd);
	str_len = ft_strlen(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		display_error_malloc('m');
	fill_map(map, str, i, str_len);
	return (close(fd), map);
}
