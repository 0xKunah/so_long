/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:42:05 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 15:51:11 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/types.h"

t_slx_coords	slx_create_coords(int x, int y)
{
	t_slx_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

int	slx_compare_coords(t_slx_coords c1, t_slx_coords c2)
{
	return (c1.x == c2.x && c1.y == c2.y);
}
