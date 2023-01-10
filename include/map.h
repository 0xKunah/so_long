/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:21:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/10 12:21:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAP_H
# define MAP_H

# ifndef TYPEDEFS_H
#  include "typedefs.h"
# endif

/* map_checker.c */
char	*check_line_validity(char *line);
void	check_map_validity(char **map);
void	check_map_solvability(t_game game);

/* drawers.c */
int		is_wall(t_game game, int i, int j);
void	draw_side_wall(int i, int j);
void	draw_wall(t_game game, int i, int j);
void	draw_floor(t_game game, int i, int j);
void	draw_map(t_game game);
#endif