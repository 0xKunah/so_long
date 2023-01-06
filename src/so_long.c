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
#include "../libft/includes/io.h"
#include "../libft/includes/memory.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	game = parse_map(argv[1]);
	i = 0;
	while (game.map[i])
	{
		ft_printf("%i: %s\n", i, game.map[i]);
		i++;
	}
	check_map_validity(game.map);
	slx_init(game.map_size.x * ASSET_SIZE,
		game.map_size.y * ASSET_SIZE, "./so_long");
	check_map_solvability(game);
	draw_map(game);
	while (game.map[i])
	{
		ft_printf("%i: %s\n", i, game.map[i]);
		i++;
	}
	slx_loop();
	ft_free_array((void **)game.map);
	slx_kill();
	return (argc - argc);
}
