/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:17 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 13:10:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"


void	slx_display_image(void *img, t_slx_coords coords)
{
	mlx_put_image_to_window(g_mlx_instance, g_mlx_window,
		img, coords.x, coords.y);
}
