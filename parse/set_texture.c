/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:18:41 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reorder_tex_tab(char ***tab, int *indexes, int i)
{
	int		swap_index;
	char	*swap_tab;

	while (--i > 0)
		if (indexes[i] < indexes[i - 1])
		{
			swap_index = indexes[i - 1];
			indexes[i - 1] = indexes[i];
			indexes[i] = swap_index;
			swap_tab = (*tab)[i - 1];
			(*tab)[i - 1] = (*tab)[i];
			(*tab)[i] = swap_tab;
		}
}

int		fill_tex_tab(char ***tab, char *tmp, int index)
{
	static int	indexes[7] = {7, 7, 7, 7, 7, 7, 7};
	static int	size = 0;
	char		**prev_tab;
	int			i;

	prev_tab = *tab;
	if (!(*tab = malloc(sizeof(char *) * (++size + 1))))
	{
		if (prev_tab != NULL)
			ft_free_tab(prev_tab);
		free(tmp);
		return (0);
	}
	indexes[size - 1] = index;
	i = -1;
	while (++i < size)
		(*tab)[i] = (i == (size - 1)) ? ft_strdup(tmp) : ft_strdup(prev_tab[i]);
	(*tab)[size] = 0;
	free(tmp);
	if (prev_tab != NULL)
		ft_free_tab(prev_tab);
	reorder_tex_tab(tab, indexes, i);
	return (1);
}

int		fill_texture(t_c3d *t, char **split)
{
	char	*tmp;

	tmp = ft_strdup(split[1]);
	if (!ft_strcmp(split[0], "NO") && fill_tex_tab(&t->tex_tab, tmp, 0))
		return (1);
	else if (!ft_strcmp(split[0], "SO") && fill_tex_tab(&t->tex_tab, tmp, 1))
		return (1);
	else if (!ft_strcmp(split[0], "EA") && fill_tex_tab(&t->tex_tab, tmp, 2))
		return (1);
	else if (!ft_strcmp(split[0], "WE") && fill_tex_tab(&t->tex_tab, tmp, 3))
		return (1);
	else if (!ft_strcmp(split[0], "S") && fill_tex_tab(&t->tex_tab, tmp, 4))
		return (1);
	else if (!ft_strcmp(split[0], "F") && fill_tex_tab(&t->tex_tab, tmp, 5))
		return ((t->tex_flr = 1));
	else if (!ft_strcmp(split[0], "C") && fill_tex_tab(&t->tex_tab, tmp, 6))
		return ((t->tex_cl = 1));
	else
		return (exit_error(TEXTURE_PROBLEM));
}

int		set_texture(t_c3d *t, char **split)
{
	char	*xpm;
	int		fd;
	int		ret;

	xpm = ft_substr(split[1], ft_strlen(split[1]) - 4, ft_strlen(split[1]));
	if (!ft_strcmp(xpm, ".xpm"))
	{
		free(xpm);
		fd = open(split[1], O_RDONLY);
		ret = (!file_exist(fd, ".xpm") || !fill_texture(t, split)) ? 0 : 1;
		close(fd);
		return (ret);
	}
	else
	{
		free(xpm);
		return (exit_error(NOT_XPM));
	}
	return (exit_error(TEXTURE_PROBLEM));
}
