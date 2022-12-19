/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:37 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/16 14:06:04 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLX_H
# define SLX_H
# include "../minilibx_macos/mlx.h"


/* ---- Type declarations ---- */
typedef struct s_slx_image {
	int		width;
	int		height;
	void	*data;
}			t_slx_image;

typedef struct s_slx_coords {
	int	x;
	int	y;
}		t_slx_coords;

/* ---- Global variables ---- */

void			slx_init(int width, int height, char *name);
void			slx_display_image(void *img, t_slx_coords coords);
void			slx_loop(void);
t_slx_image		slx_load_xpm(char *file);
t_slx_coords	slx_create_coords(int x, int y);
void			*slx_get_instance(void);
void			*slx_get_window(void);
void			slx_display_xpm(char *file, int x, int y);
void			slx_display_stacked_xpm(char *first_layer, char *second_layer,
					int x, int y);
#endif
