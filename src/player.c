/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:11:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/10 12:11:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"

void	display_player(t_game game, t_slx_image	ped)
{
	slx_display_image(ped.data,
		slx_create_coords(game.player.pos.x * ASSET_SIZE,
			game.player.pos.y * ASSET_SIZE));
}

t_player_peds	load_peds(void)
{
	t_player_peds	peds;

	peds.front = slx_load_xpm(PLAYER_FRONT);
	peds.left = slx_load_xpm(PLAYER_LEFT);
	peds.right = slx_load_xpm(PLAYER_RIGHT);
	peds.back = slx_load_xpm(PLAYER_BACK);
	return (peds);
}
