/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:52:08 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/16 14:26:55 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include "../slx/include/slx.h"
#include "../libft/includes/io.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


t_slx_coords	create_coords(int x, int y)
{
	t_slx_coords	c;

	c.x = x;
	c.y = y;
	return (c);
}

int	is_wall(char **map, int i, int j)
{
	if (i >= 0 && map[i])
	{
		if (j >= 0 && map[i][j])
			if (map[i][j] == '1')
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
}

void	draw_wall(t_game game, int i, int j)
{
	if (!is_wall(game.map, i + 1, j) && !is_wall(game.map, i - 1, j)
		&& !is_wall(game.map, i, j + 1) && !is_wall(game.map, i, j - 1))
		slx_display_xpm(LITTLE_HOLE, j * ASSET_SIZE, i * ASSET_SIZE);
	else if (i > 0 && i < game.map_size.y - 1
		&& j > 0 && j < game.map_size.x - 1)
		slx_display_stacked_xpm(BASIC_FLOOR, DECOR_BIG_ROCK,
			j * ASSET_SIZE, i * ASSET_SIZE);
	else if (is_wall(game.map, i + 1, j) && is_wall(game.map, i - 1, j))
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
	if (is_wall(game.map, i - 1, j) && is_wall(game.map, i, j))
		slx_display_xpm(FLOOR_CRACK_TL, i * ASSET_SIZE, j * ASSET_SIZE);
	else if (is_wall(game.map, i, j - 1))
		slx_display_xpm(FLOOR_CRACK_T, i * ASSET_SIZE, j * ASSET_SIZE);
	else
		slx_display_xpm(BASIC_FLOOR, i * ASSET_SIZE, j * ASSET_SIZE);
}

void	display_map(t_game game)
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
					slx_display_xpm(COLLECTIBLE, j * ASSET_SIZE, i * ASSET_SIZE);
			}
			j++;
		}
		i++;
	}
}

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
	slx_init(game.map_size.x * ASSET_SIZE, game.map_size.y * ASSET_SIZE, "./so_long");
	display_map(game);
	slx_loop();
	return (argc - argc);
}
