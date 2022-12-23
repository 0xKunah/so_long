/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:38 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/16 13:51:06 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/slx.h"
#include <stdlib.h>

typedef struct s_slx_file
{
	char				*name;
	t_slx_image			content;
	struct s_slx_file	*next;
}			t_slx_file;

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

static t_slx_file **slx_get_loaded_files()
{
	static t_slx_file	*loaded;

	return (&loaded);
}

static t_slx_image	slx_get_image(char *name)
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

static t_slx_image	slx_load_image(char *name)
{
	t_slx_file	*head;

	head = malloc(sizeof(t_slx_file));
	head->content.data = mlx_xpm_file_to_image(slx_get_instance(), name, &(head->content.width), &(head->content.height));
	head->name = ft_strdup(name);
	head->next = *slx_get_loaded_files();
	*slx_get_loaded_files() = head;
	return (head->content);
}

#include <stdio.h>

t_slx_image	slx_load_xpm(char *file)
{
	
	t_slx_image			img;

	img = slx_get_image(file);
	if (!img.data)
		return (slx_load_image(file));
	return (img);
}

#include <stdio.h>

void	slx_destroy_images()
{
	t_slx_file	*file;
	t_slx_file	*tmp;

	file = *slx_get_loaded_files();
	while (file)
	{
		printf("Freeing %s\n", file->name);
		free(file->name);
		mlx_destroy_image(slx_get_instance(), file->content.data);
		tmp = file->next;
		free(file);
		file = tmp;
	}
}