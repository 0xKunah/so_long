/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:09:29 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:13:38 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

t_slx_instance	*slx_get_instance(void)
{
	static t_slx_instance	slx;

	return (&slx);
}

void	slx_init(int width, int height, char *name)
{
	t_slx_instance	*slx;

	slx = slx_get_instance();
	slx->mlx = mlx_init();
	slx->win = mlx_new_window(slx_get_instance()->mlx, width, height, name);
}

void	slx_loop(void)
{
	mlx_loop(slx_get_instance()->mlx);
}

void	slx_kill(void)
{
	slx_destroy_images();
	mlx_destroy_window(slx_get_instance()->mlx, slx_get_instance()->win);
	exit(0);
}
