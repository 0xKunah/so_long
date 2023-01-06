/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:13:17 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/16 14:05:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"

void	slx_display_image(void *img, t_slx_coords coords)
{
	mlx_put_image_to_window(slx_get_instance().mlx, slx_get_instance().win,
		img, coords.x, coords.y);
}

void	slx_display_xpm(char *file, int x, int y)
{
	slx_display_image(slx_load_xpm(file).data, slx_create_coords(x, y));
}

void	slx_display_stacked_xpm(char *first_layer, char *second_layer,
			int x, int y)
{
	slx_display_image(slx_load_xpm(first_layer).data, slx_create_coords(x, y));
	slx_display_image(slx_load_xpm(second_layer).data, slx_create_coords(x, y));
}
