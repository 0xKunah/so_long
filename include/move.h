/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:00:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/10 14:00:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MOVE_H
# define MOVE_H

# ifndef TYPEDEFS_H
#  include "typedefs.h"
# endif

void	move(t_game *game, int key, void (*f)(t_game *));
void	on_move(t_game *game);

#endif