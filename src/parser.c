/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:07:15 by dbiguene          #+#    #+#             */
/*   Updated: 2022/12/15 11:59:37 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/string.h"
#include "../libft/includes/io.h"
#include "../libft/includes/linked_list.h"
#include "../include/typedefs.h"
#include <fcntl.h>

static char	**free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	*ft_strdup_no_nl(char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	if (s[len - 1] && s[len - 1] != '\n')
		len++;
	str = malloc((len) * sizeof(char));
	if (str)
		ft_strlcpy(str, s, len);
	return (str);
}

static char	**list_to_array(t_list *lst)
{
	size_t	size;
	size_t	i;
	char	**tab;

	size = ft_lstsize(lst);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_strdup_no_nl(lst->content);
		if (!tab[i])
			return (free_tab(tab));
		lst = lst->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	check_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path) - 1;
	if (path[len] == 'r' && path[len - 1] == 'e'
		&& path[len - 2] == 'b' && path[len - 3] == '.')
		return ;
	ft_printf("\033[0;31m[map_error]: Map is not using .ber extension");
	exit(1);
}

t_game	parse_map(char *path)
{
	t_game	game;
	t_list	*lines;
	char	*line;
	int		fd;

	check_extension(path);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	lines = NULL;
	while (line)
	{
		if (lines)
			ft_lstadd_back(&lines, ft_lstnew(line));
		else
			lines = ft_lstnew(line);
		line = get_next_line(fd);
	}
	game.map_size.y = ft_lstsize(lines);
	game.map = list_to_array(lines);
	game.map_size.x = (int)ft_strlen(game.map[0]);
	ft_lstclear(&lines, free);
	close(fd);
	return (game);
}
