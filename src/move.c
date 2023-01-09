/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:13:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/09 15:13:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include <stdio.h>

void	move(t_game *game, int key)
{
	draw_floor(*game, game->player_pos.y, game->player_pos.x);
	if (key == KEY_W)
		game->player_pos.y--;
	else if (key == KEY_S)
		game->player_pos.y++;
	else if (key == KEY_A)
		game->player_pos.x--;
	else
		game->player_pos.x++;
	display_player(*game);
}
