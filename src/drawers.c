/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:49:50 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:42:43 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"

int	is_wall(t_game game, int i, int j)
{
	if (i >= 0 && i < game.map_size.y)
	{
		if (j >= 0 && j < game.map_size.x)
			if (game.map[i][j] == '1')
				return (1);
		return (0);
	}
	return (0);
}

void	draw_side_wall(int i, int j)
{
	if (j > 0)
	{
		if (i == 1)
			slx_display_stacked_xpm(FLOOR_CRACK_TR, WALL_R,
				j * ASSET_SIZE, i * ASSET_SIZE);
		else
			slx_display_stacked_xpm(FLOOR_CRACK_R, WALL_R,
				j * ASSET_SIZE, i * ASSET_SIZE);
	}
	else
	{
		if (i == 1)
			slx_display_stacked_xpm(FLOOR_CRACK_TL, WALL_L,
				j * ASSET_SIZE, i * ASSET_SIZE);
		else
			slx_display_stacked_xpm(FLOOR_CRACK_L, WALL_L,
				j * ASSET_SIZE, i * ASSET_SIZE);
	}
	slx_display_xpm(DECOR_BIG_ROCK, j * ASSET_SIZE, i * ASSET_SIZE);
}

void	draw_wall(t_game game, int i, int j)
{
	if (i > 0 && i < game.map_size.y - 1
		&& j > 0 && j < game.map_size.x - 1)
	{
		if (i == 1)
			slx_display_stacked_xpm(FLOOR_CRACK_T, DECOR_BIG_ROCK,
				j * ASSET_SIZE, i * ASSET_SIZE);
		else
			slx_display_stacked_xpm(BASIC_FLOOR, DECOR_BIG_ROCK,
				j * ASSET_SIZE, i * ASSET_SIZE);
	}
	else if (is_wall(game, i + 1, j) && is_wall(game, i - 1, j))
		draw_side_wall(i, j);
	else
	{
		slx_display_xpm(WALL_TB, j * ASSET_SIZE, i * ASSET_SIZE);
		if (j == 0 && i == 0)
			slx_display_xpm(WALL_L, j * ASSET_SIZE, i * ASSET_SIZE);
		else if (j == game.map_size.x - 1 && i == 0)
			slx_display_xpm(WALL_R, j * ASSET_SIZE, i * ASSET_SIZE);
	}
}

void	draw_floor(t_game game, int i, int j)
{
	if (is_wall(game, i - 1, j) && is_wall(game, i, j))
		slx_display_xpm(FLOOR_CRACK_TL, j * ASSET_SIZE, i * ASSET_SIZE);
	else if (i == 1
		&& !(i - 1 > 0 && i - 1 < game.map_size.y - 1
			&& j - 1 > 0 && j - 1 < game.map_size.x - 1))
		slx_display_xpm(FLOOR_CRACK_T, j * ASSET_SIZE, i * ASSET_SIZE);
	else
		slx_display_xpm(BASIC_FLOOR, j * ASSET_SIZE, i * ASSET_SIZE);
}

void	draw_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == '1')
				draw_wall(game, i, j);
			else
			{
				draw_floor(game, i, j);
				if (game.map[i][j] == 'C')
					slx_display_xpm(COLLECTIBLE,
						j * ASSET_SIZE, i * ASSET_SIZE);
			}
			j++;
		}
		i++;
	}
}
