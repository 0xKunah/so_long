/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:57:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/06 15:57:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef IMAGES_H
# define IMAGES_H

t_slx_image		slx_load_xpm(char *file);
void			slx_destroy_images(void);
void			slx_display_xpm(char *file, int x, int y);
void			slx_display_image(void *img, t_slx_coords coords);
void			slx_display_stacked_xpm(char *first_layer, char *second_layer,
					int x, int y);
#endif