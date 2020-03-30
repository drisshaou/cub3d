/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:17:17 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_int(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

int	set_color(t_c3d *t, char **split)
{
	char	**rgb;
	int		i;
	int		j;
	int		rgb_i;
	int		ret;

	rgb = ft_split(split[1], ',');
	if ((ret = 1) && ft_get_tab_size(rgb) == 3 && (i = -1))
	{
		while (++i < 3 && (j = -1))
			while (rgb[i][++j])
				ret = !ft_isdigit(rgb[i][j]) || ft_atoi(rgb[i]) > 255 ? 0 : ret;
		if (ret == 1)
		{
			rgb_i = rgb_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
			t->flr_color = !ft_strcmp(split[0], "F") ? rgb_i : t->flr_color;
			t->cl_color = !ft_strcmp(split[0], "C") ? rgb_i : t->cl_color;
		}
	}
	else if (!set_texture(t, split))
		ret = -1;
	ft_free_tab(rgb);
	if (ret == -1)
		return (0);
	return (ret == 0 ? exit_error(COLOR_PROBLEM) : 1);
}
