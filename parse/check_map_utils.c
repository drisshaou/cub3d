/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:20:20 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 06:49:51 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_visited(t_path ***path, int x, int y, int i)
{
	while (i > 0 && i-- > 0)
		if ((*path)[i]->x == x && (*path)[i]->y == y)
			return (1);
	return (0);
}

int		try_player_pos(char ***map, t_path ***path, int x, int y, int i)
{
	return (x >= 0 && (x < ft_get_tab_size(*map))
		&& y >= 0 && y < (int)ft_strlen((*map)[x])
		&& !is_visited(path, x, y, i)
		&& (*map)[x][y] != '1');
}

int		get_ways(char ***map, t_path ***path, t_int c, int i)
{
	int	nb;

	nb = 0;
	if (try_player_pos(map, path, c.x, c.y - 1, i))
		nb++;
	if (try_player_pos(map, path, c.x + 1, c.y, i))
		nb++;
	if (try_player_pos(map, path, c.x, c.y + 1, i))
		nb++;
	if (try_player_pos(map, path, c.x - 1, c.y, i))
		nb++;
	return (nb);
}

void	move_to(char ***map, t_path ***path, t_int *c, int i)
{
	if (try_player_pos(map, path, c->x, c->y - 1, i))
		(c->y)--;
	else if (try_player_pos(map, path, c->x + 1, c->y, i))
		(c->x)++;
	else if (try_player_pos(map, path, c->x, c->y + 1, i))
		(c->y)++;
	else if (try_player_pos(map, path, c->x - 1, c->y, i))
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
		if ((nb = get_ways(map, path, *c, i)) >= 1)
			break ;
	}
	return ((j == 0 && nb == 0) ? 0 : 1);
}
