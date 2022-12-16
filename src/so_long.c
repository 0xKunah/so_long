/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:52:08 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 14:45:50 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/assets_path.h"
#include "../slx/include/slx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#include "../libft/includes/io.h"

t_slx_coords	create_coords(int x, int y)
{
	t_slx_coords	c;

	c.x = x;
	c.y = y;
	return (c);
}

int	is_wall(char **map, int i, int j)
{
	if (map[i])
	{
		if (map[i][j])
			if (map[i][j] == '1')
				return (1);
		return (0);
	}
	return (0);
}

void	draw_wall(char **map, int i, int j)
{
	t_slx_image	img;

	if (!is_wall(map, i + 1, j) && !is_wall(map, i - 1, j)
		&& !is_wall(map, i, j + 1) && !is_wall(map, i, j - 1))
		img = slx_load_xpm(LITTLE_HOLE);
	else if (is_wall(map, i + 1, j) && is_wall(map, i - 1, j))
	{
		if (map[i][j - 1])
			img = slx_load_xpm(WALL_R);
		else
			img = slx_load_xpm(WALL_L);
	}
	else
		img = slx_load_xpm(WALL_TB);
	slx_display_image(img.data, create_coords(j * 32, i * 32));
}

void	display_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_wall(map, i, j);
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
	slx_init(game.map_size.x * 32, game.map_size.y * 32, "./so_long");
	check_map_validity(game.map);
	display_map(game.map);
	slx_loop();
	return (argc - argc);
}
