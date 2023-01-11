/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:45:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:14:24 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stddef.h>

int	key_down(int key, int (*handler)(int))
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	handler(key);
	return (0);
}

int	close_hook(void)
{
	slx_kill();
	return (0);
}

void	slx_hook(int (*handler)(int))
{
	mlx_hook(slx_get_instance()->win, ON_KEYDOWN, 2, &key_down, handler);
	mlx_hook(slx_get_instance()->win, ON_DESTROY, 0, &close_hook, NULL);
}
