/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:20:20 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 17:18:06 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_visited(t_path ***path, t_int d, int i)
{
	while (i > 0 && i-- > 0)
		if ((*path)[i]->x == d.x && (*path)[i]->y == d.y)
			return (1);
	return (0);
}

int		try_pos(char ***map, t_path ***path, t_int d, int i)
{
	return (d.x >= 0 && (d.x < ft_get_tab_size(*map))
		&& d.y >= 0 && d.y < (int)ft_strlen((*map)[d.x])
		&& !is_visited(path, d, i)
		&& (*map)[d.x][d.y] != '1');
}

int		nb_ways(char ***map, t_path ***path, t_int c, int i)
{
	int		nb;

	nb = 0;
	if (try_pos(map, path, tni_t(c.x, c.y - 1), i))
		nb++;
	if (try_pos(map, path, tni_t(c.x + 1, c.y), i))
		nb++;
	if (try_pos(map, path, tni_t(c.x, c.y + 1), i))
		nb++;
	if (try_pos(map, path, tni_t(c.x - 1, c.y), i))
		nb++;
	return (nb);
}

void	move_to(char ***map, t_path ***path, t_int *c, int i)
{
	if (try_pos(map, path, tni_t(c->x, c->y - 1), i))
		(c->y)--;
	else if (try_pos(map, path, tni_t(c->x + 1, c->y), i))
		(c->x)++;
	else if (try_pos(map, path, tni_t(c->x, c->y + 1), i))
		(c->y)++;
	else if (try_pos(map, path, tni_t(c->x - 1, c->y), i))
		(c->x)--;
}

int		move_back(char ***map, t_path ***path, t_int *c, int i)
{
	int	j;
	int	nb;

	j = i;
	nb = 0;
	while (j > 0 && --j >= 0)
	{
		*c = (t_int){(*path)[j]->x, (*path)[j]->y};
		if ((nb = nb_ways(map, path, *c, i)) >= 1)
			break ;
	}
	return ((j == 0 && nb == 0) ? 0 : 1);
}
