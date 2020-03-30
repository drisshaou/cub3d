/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:14:10 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:59 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_validated(char ***map, t_path ***path, t_int c, t_double dest, int i)
{
	if (c.x == (int)dest.x && c.y == (int)dest.y && !get_ways(map, path, c, i))
		return (1);
	return (0);
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

	i = 0;
	j = 1;
	c = (t_int){(int)pos.x, (int)pos.y};
	is_valid = 0;
	*((*path)[i++]) = (t_path){c.x, c.y, 2};
	while (!(j == 0 || is_valid))
	{
		if ((nb = get_ways(map, path, c, i)) > 0)
		{
			move_to(map, path, &c, i);
			*((*path)[i++]) = (t_path){c.x, c.y, nb};
		}
		else
			j = move_back(map, path, &c, i);
		is_valid = is_validated(map, path, c, pos, i);
		if (!is_inside(map, c))
			return (0);
	}
	return (is_valid);
}

int		check_map(char ***map, t_double pos)
{
	int		is_valid;
	int		rows;
	int		cols;
	int		x;
	t_path	**path;

	rows = ft_get_tab_size(*map);
	if (*map != NULL && (x = - 1) && !(cols = 0))
		while (++x < rows)
			if (cols < (int)ft_strlen((*map)[x]))
				cols = (int)ft_strlen((*map)[x]);
	if ((x = - 1) && !(path = malloc(sizeof(t_path*) * (rows * cols))))
		return (exit_error(CANT_CHECK_MAP));
	while (++x < rows * cols)
		if (!(path[x] = malloc(sizeof(t_path))))
			return (exit_error(CANT_CHECK_MAP));
	is_valid = track_map_borders(map, &path, pos);
	x = -1;
	while (++x < (rows * cols))
		free(path[x]);
	free(path);
	if (!is_valid)
		return (exit_error(MAP_INVALID));
	else
		return (is_valid);
}
