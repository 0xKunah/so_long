/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:32:58 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/05 12:39:12 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n && s1[i] && s2[i]
		&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		;
	if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] || i == n)
		return (0);
	else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		return (1);
	else
		return (-1);
}

t_slx_file	**slx_get_loaded_files(void)
{
	static t_slx_file	*loaded;

	return (&loaded);
}

t_slx_image	slx_get_image(char *name)
{
	t_slx_image	null_image;
	t_slx_file	*file;

	file = *slx_get_loaded_files();
	while (file)
	{
		if (!ft_strncmp(file->name, name, ft_strlen(name)))
			return (file->content);
		file = file->next;
	}
	null_image.data = NULL;
	null_image.width = 0;
	null_image.height = 0;
	return (null_image);
}
