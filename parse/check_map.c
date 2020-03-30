/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:14:10 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 23:29:50 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_int	tni_t(int x, int y)
{
	t_int	d;

	d = (t_int){x, y};
	return (d);
}

int		is_inside(char ***map, t_int c)
{
	if (c.y > 0 && c.y < (int)(ft_strlen((*map)[c.x]) - 1)
		&& c.x > 0 && c.x < (int)(ft_get_tab_size(*map) - 1)
		&& c.y < (int)ft_strlen((*map)[c.x - 1]) && (*map)[c.x - 1][c.y] != ' '
		&& c.y < (int)ft_strlen((*map)[c.x + 1]) && (*map)[c.x + 1][c.y] != ' '
		&& (*map)[c.x][c.y] != ' ')
		return (1);
	return (0);
}

int		track_map_borders(char ***map, t_path ***path, t_double pos)
{
	int		is_valid;
	t_int	c;
	int		nb;
	int		i;
	int		j;

	i = 1;
	j = 1;
	c = (t_int){(int)pos.x, (int)pos.y};
	is_valid = 0;
	while (!(j == 0 || is_valid))
	{
		if ((nb = nb_ways(map, path, c, i)) > 0)
		{
			move_to(map, path, &c, i);
			*((*path)[i++]) = (t_path){c.x, c.y, nb};
		}
		else
			j = move_back(map, path, &c, i);
		if (c.x == (int)pos.x && c.y == (int)pos.y && !nb_ways(map, path, c, i))
			is_valid = 1;
		if (!is_inside(map, c))
			return (0);
	}
	return (is_valid);
}

int		check_map(char ***map, t_double pos)
{
	int		is_valid;
	int		x;
	t_int	max;
	t_path	**path;

	max = (t_int){ft_get_tab_size(*map), 0};
	if (*map != NULL && (x = -1))
		while (++x < max.x)
			if (max.y < (int)ft_strlen((*map)[x]))
				max.y = (int)ft_strlen((*map)[x]);
	x = -1;
	if (!(path = malloc(sizeof(t_path*) * (max.x * max.y))))
		return (exit_error(CANT_CHECK_MAP));
	while (++x < max.x * max.y)
		if (!(path[x] = malloc(sizeof(t_path))))
			return (exit_error(CANT_CHECK_MAP));
	(*path)[0] = (t_path){(int)pos.x, (int)pos.y, 2};
	is_valid = track_map_borders(map, &path, pos);
	x = -1;
	while (++x < (max.x * max.y))
		free(path[x]);
	free(path);
	return (!is_valid ? exit_error(MAP_INVALID) : is_valid);
}
