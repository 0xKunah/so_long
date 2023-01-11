/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:27:55 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:31:24 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/io.h"
#include <stdlib.h>

void	print_error(char *str)
{
	ft_printf("\033[1;31m %s\033[1;00m", str);
	exit(1);
}
