/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:52:19 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 15:55:20 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "typedefs.h"
# include "../slx/include/slx.h"

t_game	parse_map(char *path);
void	check_map_validity(char **map);

void	draw_side_wall(int i, int j);
void	draw_wall(t_game game, int i, int j);
void	draw_floor(t_game game, int i, int j);
void	draw_map(t_game game);
int		is_wall(t_game game, int i, int j);

void	check_map_solvability(t_game game);

void	display_player(t_game game);
void	move(t_game *game, int key);

#endif
