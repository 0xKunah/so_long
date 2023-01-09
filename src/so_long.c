/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:52:08 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 15:55:31 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/io.h"

t_game	*get_game_instance(void)
{
	static t_game	game;

	return (&game);
}

int	key_handler(int key)
{
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move(get_game_instance(), key);
	else if (key == KEY_ESC)
		slx_kill();
	return (0);
}

t_slx_coords	get_player_pos(t_game game)
{
	t_slx_coords	coords;

	coords.y = 0;
	while (coords.y < game.map_size.y)
	{
		coords.x = 0;
		while (coords.x < game.map_size.x)
		{
			if (game.map[coords.y][coords.x] == 'P')
				return (coords);
			coords.x++;
		}
		coords.y++;
	}
	return (coords);
}

void	display_player(t_game game)
{
	slx_display_image(game.player_img.data,
		slx_create_coords(game.player_pos.x * ASSET_SIZE,
			game.player_pos.y * ASSET_SIZE));
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = get_game_instance();
	*game = parse_map(argv[1]);
	check_map_validity(game->map);
	slx_init(game->map_size.x * ASSET_SIZE,
		game->map_size.y * ASSET_SIZE, "./so_long");
	check_map_solvability(*game);
	draw_map(*game);
	game->player_pos = get_player_pos(*game);
	game->player_img = slx_load_xpm(PLAYER_FRONT);
	display_player(*game);
	slx_hook(&key_handler);
	slx_loop();
	return (argc - argc);
}
