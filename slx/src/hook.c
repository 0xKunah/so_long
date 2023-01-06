/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:45:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/06 15:45:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"

int	key_down(int key, t_slx_keys *keys)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	keys->list[key] = 1;
	keys->pressed++;
	return (0);
}

int	key_up(int key, t_slx_keys *keys)
{
	if (key < 0 || key >= MAX_KEY)
		return (-1);
	keys->list[key] = 0;
	keys->pressed--;
	return (0);
}

int	close_window_hook(t_slx_instance *instance)
{
	(void)instance;
	slx_kill();
	return (0);
}

void	slx_hook(t_slx_instance *instance, t_slx_keys *keys)
{
	mlx_hook(instance->win, ON_KEYDOWN, 2, &key_down, keys);
	mlx_hook(instance->win, ON_KEYUP, 3, &key_up, keys);
	mlx_hook(instance->win, ON_DESTROY, 0, &close_window_hook, instance);
}
