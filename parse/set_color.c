/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 04:17:17 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/31 01:07:11 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_int(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
}

void	fill_color(t_c3d *t, char *str, char **rgb)
{
	int		rgb_i;

	rgb_i = rgb_int(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	t->flr_color = !ft_strcmp(str, "F") ? rgb_i : t->flr_color;
	t->cl_color = !ft_strcmp(str, "C") ? rgb_i : t->cl_color;
}

int		set_color(t_c3d *t, char **split)
{
	char	**rgb;
	int		i;
	int		j;
	int		ret;

	ret = 1;
	rgb = ft_split(split[1], ',');
	if (ft_get_tab_size((rgb)) == 3 && (i = -1))
	{
		while (++i < 3 && (j = -1))
			while (rgb[i][++j])
				ret = !ft_isdigit(rgb[i][j]) || ft_atoi(rgb[i]) > 255 ? 0 : ret;
		if (ret == 1)
			fill_color(t, split[0], rgb);
	}
	else if (!set_texture(t, split))
		ret = -1;
	ft_free_tab(rgb);
	if (ret == -1 || ret == 0)
		return (ret == 0 ? exit_error(COLOR_PROBLEM) : 0);
	return (1);
}
