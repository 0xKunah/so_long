/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:15:38 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/14 14:09:29 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/io.h"
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