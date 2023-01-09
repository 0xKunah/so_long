/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:09:01 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 11:56:51 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include "../slx/include/slx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_game {
	char			**map;
	t_slx_coords	map_size;
	t_slx_coords	player_pos;
	t_slx_image		player_img;
}				t_game;

typedef struct s_player_peds {
	t_slx_image	front;
	t_slx_image	left;
	t_slx_image	right;
	t_slx_image	back;
}				t_player_peds;

#endif
