/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:09:29 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 12:48:26 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

static t_slx_instance	g_slx;

void	slx_init(int width, int height, char *name)
{
	g_slx.mlx = mlx_init();
	g_slx.win = mlx_new_window(g_slx.mlx, width, height, name);
}

void	slx_loop(void)
{
	mlx_loop(g_slx.mlx);
}

t_slx_instance	slx_get_instance(void)
{
	return (g_slx);
}

void	slx_kill(void)
{
	slx_destroy_images();
	mlx_clear_window(slx_get_instance().mlx, slx_get_instance().win);
	mlx_destroy_window(slx_get_instance().mlx, slx_get_instance().win);
}
