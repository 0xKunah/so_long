/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:38 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/11 12:14:43 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

t_slx_file	**slx_get_loaded_files(void);
t_slx_image	slx_get_image(char *name);

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

static char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static t_slx_image	slx_load_image(char *name)
{
	t_slx_file	*head;

	head = malloc(sizeof(t_slx_file));
	head->content.data = mlx_xpm_file_to_image(slx_get_instance()->mlx, name,
			&(head->content.width), &(head->content.height));
	head->name = ft_strdup(name);
	head->next = *slx_get_loaded_files();
	*slx_get_loaded_files() = head;
	return (head->content);
}

t_slx_image	slx_load_xpm(char *file)
{
	t_slx_image			img;

	img = slx_get_image(file);
	if (!img.data)
		return (slx_load_image(file));
	return (img);
}

void	slx_destroy_images(void)
{
	t_slx_file	*file;
	t_slx_file	*tmp;

	file = *slx_get_loaded_files();
	while (file)
	{
		free(file->name);
		mlx_destroy_image(slx_get_instance()->mlx, file->content.data);
		tmp = file->next;
		free(file);
		file = tmp;
	}
}
