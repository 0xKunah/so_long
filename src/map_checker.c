/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:15:38 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/06 13:45:43 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/io.h"
#include "../include/so_long.h"
#include <stdio.h>

char	*check_line_validity(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			return ("contains invalid characters");
		i++;
	}
	if (line[0] != '1' || line[i - 1] != '1')
		return ("is not closed (starts and ends with wall)");
	return (NULL);
}

void	check_map_validity(char **map)
{
	int	i;

	i = 0;
	if (!map)
	{
		ft_printf("\033[0;31m[map_error] No map given\033[0;00m");
		exit(1);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_printf("\033[0;31m[map_error] Map is not a rectangle\033[0;00m");
			exit (1);
		}
		if (check_line_validity(map[i]))
		{
			ft_printf("\033[0;31m[map_error] Line %d %s\033[0;00m", i,
				check_line_validity(map[i]));
			exit(1);
		}
		i++;
	}
}

void	fill_map(char **map, int x, int y)
{
	if (map[x][y] == '1')
		return ;
	map[x][y] = 'F';
	if (map[x + 1][y] != '1')
		fill_map(map, x + 1, y);
	if (map[x][y + 1] != '1')
		fill_map(map, x, y + 1);
	if (map[x - 1][y] != '1' && map[x - 1][y] != 'F')
		fill_map(map, x - 1, y);
	if (map[x][y - 1] != '1' && map[x][y - 1] != 'F')
		fill_map(map, x, y - 1);
}

void	check_map_solvability(t_game game)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (game.map_size.y + 1));
	while (game.map[i])
	{
		map[i] = ft_strdup(game.map[i]);
		i++;
	}
	map[i] = NULL;
	fill_map(map, 1, 1);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'P')
			|| ft_strchr(map[i], '0'))
		{
			ft_printf("\033[0;31m[map_error] Map is not solvable\033[0;00m");
			exit(1);
		}
		i++;
	}
	ft_free_array((void **)map);
}
