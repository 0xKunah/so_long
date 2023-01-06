/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:57:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/06 15:57:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef TYPES_H
# define TYPES_H

typedef struct s_slx_image {
	int		width;
	int		height;
	void	*data;
}			t_slx_image;

typedef struct s_slx_coords {
	int	x;
	int	y;
}		t_slx_coords;

typedef struct s_slx_instance
{
	void	*mlx;
	void	*win;
}			t_slx_instance;

typedef struct s_slx_file
{
	char				*name;
	t_slx_image			content;
	struct s_slx_file	*next;
}						t_slx_file;

#endif