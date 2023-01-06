/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef HOOK_H
# define HOOK_H

# include "types.h"
# define MAX_KEY 270

typedef struct s_slx_keys
{
	int		list[MAX_KEY];
	int		pressed;
}	t_slx_keys;

enum
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_E = 14,
	KEY_Q = 12,
	KEY_SPACE = 49,
	KEY_SLASH = 44,
	KEY_L_SHIFT = 257,
	KEY_R_SHIFT = 258,
	KEY_R_CTRL = 269,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_P = 35,
	KEY_V = 9,
	KEY_C = 8,
	KEY_DOT = 47,
	KEY_S_QUOTE = 39,
	KEY_SEMI_COLON = 41,
};

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		key_down(int key, t_slx_keys *keys);
int		key_up(int key, t_slx_keys *keys);
int		close_window_hook(t_slx_instance *instance);
void	slx_hook(t_slx_instance *instance, t_slx_keys *keys);

#endif