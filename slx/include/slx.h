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
# include "../mlx/macos/mlx.h"
# include "types.h"
# include "coords.h"
# include "hook.h"
# include "images.h"

void			slx_init(int width, int height, char *name);
t_slx_instance	slx_get_instance(void);
void			slx_loop(void);
void			slx_kill(void);

#endif
