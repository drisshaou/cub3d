/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sky_flr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:17:54 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/23 03:31:46 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_sky_flr(t_c3d *t)
{
	int	y;
	int	p;

	y = t->winh * 0.5 + 1;
	while (y < t->winh)
	{
		p = y - t->winh * 0.5;
		t->pos.z = 0.5 * t->winh;
		t->rwdist = t->pos.z / p;
		t->flrstp.x = t->rwdist
			* ((t->dir.x + t->pln.x) - (t->dir.x - t->pln.x)) / t->winw;
		t->flrstp.y = t->rwdist
			* ((t->dir.y + t->pln.y) - (t->dir.y - t->pln.y)) / t->winw;
		t->flr.x = t->pos.x + t->rwdist * (t->dir.x - t->pln.x);
		t->flr.y = t->pos.y + t->rwdist * (t->dir.y - t->pln.y);
		t->shadedist = t->rwdist;
		draw_sky_flr(t, y);
		y++;
	}
}
