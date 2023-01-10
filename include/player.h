/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:12:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/10 12:12:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# ifndef TYPEDEFS_H
#  include "typedefs.h"
# endif

void			display_player(t_game game, t_slx_image	ped);
t_player_peds	load_peds(void);
#endif
