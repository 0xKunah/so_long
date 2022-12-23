/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:09:29 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/16 13:50:15 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

static void	*g_mlx_instance;
static void	*g_mlx_window;

void	slx_init(int width, int height, char *name)
{
	g_mlx_instance = mlx_init();
	g_mlx_window = mlx_new_window(g_mlx_instance, width, height, name);
}

void	slx_loop(void)
{
	mlx_loop(g_mlx_instance);
}

void	*slx_get_instance(void)
{
	return (g_mlx_instance);
}

void	*slx_get_window(void)
{
	return (g_mlx_window);
}

t_slx_coords	slx_create_coords(int x, int y)
{
	t_slx_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

void	slx_kill(void)
{
	slx_destroy_images();
	mlx_clear_window(slx_get_instance(), slx_get_window());
	mlx_destroy_window(slx_get_instance(), slx_get_window());
	free(g_mlx_instance);
	exit(0);
}