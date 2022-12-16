/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:37 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 13:42:51 by dbiguene         ###   ########lyon.fr   */
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
void	*g_mlx_instance;
void	*g_mlx_window;

void		slx_init(int width, int height, char *name);
void		slx_display_image(void *img, t_slx_coords coords);
void		slx_loop(void);
t_slx_image	slx_load_xpm(char *file);

#endif
