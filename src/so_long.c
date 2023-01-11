/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:52:08 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:30:34 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include "../libft/includes/io.h"
#include "../libft/includes/memory.h"

t_game	*get_game_instance(void)
{
	static t_game	game;

	return (&game);
}

t_slx_coords	get_pos(t_game game, char c)
{
	t_slx_coords	coords;

	coords.y = 0;
	while (coords.y < game.map_size.y)
	{
		coords.x = 0;
		while (coords.x < game.map_size.x)
		{
			if (game.map[coords.y][coords.x] == c)
				return (coords);
			coords.x++;
		}
		coords.y++;
	}
	return (coords);
}

int	key_handler(int key)
{
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move(get_game_instance(), key, &on_move);
	else if (key == KEY_ESC)
	{
		ft_free_array((void **)get_game_instance()->map);
		slx_kill();
	}
	return (0);
}

int	count_collectibles(t_game game)
{
	int	i;
	int	j;
	int	collectibles;
	int	counter[2];

	collectibles = 0;
	counter[0] = 0;
	counter[1] = 0;
	i = -1;
	while (++i < game.map_size.y)
	{
		j = -1;
		while (++j < game.map_size.x)
		{
			if (game.map[i][j] == 'C')
				collectibles++;
			else if (game.map[i][j] == 'P')
				counter[0]++;
			else if (game.map[i][j] == 'E')
				counter[1]++;
			if (counter[0] > 1 || counter[1] > 1)
				return (-1);
		}
	}
	return (collectibles);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
		print_error(" [map_error]: No map given");
	game = get_game_instance();
	*game = parse_map(argv[1]);
	check_map_validity(game->map);
	slx_init(game->map_size.x * ASSET_SIZE,
		game->map_size.y * ASSET_SIZE, "./so_long");
	check_map_solvability(*game);
	draw_map(*game);
	game->player.pos = get_pos(*game, 'P');
	game->player.peds = load_peds();
	game->collectibles = count_collectibles(*game);
	if (game->collectibles == -1)
		print_error(" [map_error]: Multiple exits or players");
	game->moves_count = 0;
	game->end_pos = get_pos(*game, 'E');
	display_player(*game, game->player.peds.front);
	slx_hook(&key_handler);
	slx_loop();
	return (argc - argc);
}
