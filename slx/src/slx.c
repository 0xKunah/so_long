/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:09:29 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 13:46:37 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"

void	slx_init(int width, int height, char *name)
{
	g_mlx_instance = mlx_init();
	g_mlx_window = mlx_new_window(g_mlx_instance, width, height, name);
}

void	slx_loop(void)
{
	mlx_loop(g_mlx_instance);
}
