/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:12:41 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/20 09:11:14 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_sprite(t_c3d *t, t_sprite ***sprites)
{
	int			i;
	t_sprite	**s_tmp;

	i = -1;
	s_tmp = *sprites;
	if (!(*sprites = malloc(sizeof(t_sprite *) * (t->nbsprites + 1))))
		return (0);
	while (++i <= t->nbsprites)
		if (!((*sprites)[i] = malloc(sizeof(t_sprite))))
			return (0);
	i = -1;
	while (++i < t->nbsprites)
		*((*sprites)[i]) = (t_sprite){s_tmp[i]->x, s_tmp[i]->y, s_tmp[i]->txid};
	if (s_tmp != NULL)
		free_sprite(t, s_tmp);
	return (1);
}

int		find_sprites(t_c3d *t)
{
	int			x;
	int			y;

	t->nbsprites = 0;
	x = -1;
	while (++x < ft_get_tab_size(t->map) && (y = -1))
		while (++y < (int)ft_strlen(t->map[x]))
			if (t->map[x][y] == '2')
			{
				t->map[x][y] = '0';
				if (!fill_sprite(t, &t->sprites))
				{
					free_sprite(t, t->sprites);
					return (exit_error(CANT_MALLOC_SPRITE));
				}
				*(t->sprites[t->nbsprites]) = (t_sprite){x + 0.5, y + 0.5, 4};
				t->nbsprites++;
			}
	if (!t->nbsprites)
		return (exit_error(CANT_FIND_SPRITE));
	return (1);
}
