/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:38 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 13:14:35 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"

t_slx_image	slx_load_xpm(char *file)
{
	t_slx_image	img;

	img.data = mlx_xpm_file_to_image(g_mlx_instance, file,
			&img.width, &img.height);
	return (img);
}
