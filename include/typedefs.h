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

typedef struct s_player_peds {
	t_slx_image	front;
	t_slx_image	left;
	t_slx_image	right;
	t_slx_image	back;
}				t_player_peds;

typedef struct s_player
{
	t_slx_coords	pos;
	t_player_peds	peds;
}					t_player;

typedef struct s_game {
	char			**map;
	t_slx_coords	map_size;
	t_player		player;
	t_slx_coords	end_pos;
	int				collectibles;
	int				moves_count;
}				t_game;

#endif
