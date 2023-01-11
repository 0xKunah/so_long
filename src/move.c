/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:27:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:15:37 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include "../libft/includes/io.h"
#include "../libft/includes/memory.h"

int	can_move(t_game game, t_slx_coords next_pos)
{
	return (game.map[next_pos.y][next_pos.x] != '1');
}

t_slx_coords	update_pos(t_game *game, int key, t_slx_image *ped,
					t_slx_coords *new_pos)
{
	*new_pos = slx_create_coords(game->player.pos.x, game->player.pos.y);
	if (key == KEY_W)
	{
		new_pos->y--;
		*ped = game->player.peds.back;
	}
	else if (key == KEY_S)
	{
		new_pos->y++;
		*ped = game->player.peds.front;
	}
	else if (key == KEY_A)
	{
		new_pos->x--;
		*ped = game->player.peds.left;
	}
	else if (key == KEY_D)
	{
		new_pos->x++;
		*ped = game->player.peds.right;
	}
	if (can_move(*game, *new_pos))
		return (*new_pos);
	return (game->player.pos);
}

void	move(t_game *game, int key, void (*f)(t_game *))
{
	t_slx_image		ped;
	t_slx_coords	new_pos;

	draw_floor(*game, game->player.pos.y, game->player.pos.x);
	new_pos = update_pos(game, key, &ped, &new_pos);
	if (!slx_compare_coords(new_pos, game->player.pos))
	{
		game->player.pos = new_pos;
		if (!slx_compare_coords(game->end_pos, game->player.pos))
			draw_floor(*game, game->player.pos.y, game->player.pos.x);
		f(game);
	}
	display_player(*game, ped);
}

void	on_move(t_game *game)
{
	if (game->map[game->player.pos.y][game->player.pos.x] == 'C')
	{
		game->collectibles--;
		game->map[game->player.pos.y][game->player.pos.x] = '0';
		if (!game->collectibles)
			slx_display_xpm(LITTLE_HOLE,
				game->end_pos.x * ASSET_SIZE, game->end_pos.y * ASSET_SIZE);
	}
	if (!game->collectibles
		&& slx_compare_coords(game->player.pos, game->end_pos))
	{
		ft_free_array((void **)game->map);
		ft_printf("\033[1;32mYou finished the game, GG !\033[1;00m");
		slx_kill();
	}
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}
