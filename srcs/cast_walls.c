/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:35:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 20:19:06 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_walls(t_c3d *t)
{
	t->x = 0;
	while (t->x < t->winw)
	{
		init_cast_walls(t);
		calc_side_dist(t);
		perform_dda(t);
		calc_draw_limits(t);
		draw_wall(t);
		t->bufz[t->x] = t->perpwdist;
		(t->x)++;
	}
}

void	init_cast_walls(t_c3d *t)
{
	double	camx;

	camx = (2 * t->x) / (double)(t->winw) - 1;
	t->raydir.x = t->dir.x + t->pln.x * camx;
	t->raydir.y = t->dir.y + t->pln.y * camx;
	t->mp.x = (int)t->pos.x;
	t->mp.y = (int)t->pos.y;
}

void	calc_side_dist(t_c3d *t)
{
	t->ddist.x = fabs(1 / t->raydir.x);
	t->ddist.y = fabs(1 / t->raydir.y);
	t->stp.x = 1;
	t->sdist.x = (t->mp.x + 1.0 - t->pos.x) * t->ddist.x;
	if (t->raydir.x < 0 && (t->stp.x = -1))
		t->sdist.x = (t->pos.x - t->mp.x) * t->ddist.x;
	t->stp.y = 1;
	t->sdist.y = (t->mp.y + 1.0 - t->pos.y) * t->ddist.y;
	if (t->raydir.y < 0 && (t->stp.y = -1))
		t->sdist.y = (t->pos.y - t->mp.y) * t->ddist.y;
}

void	perform_dda(t_c3d *t)
{
	t->hit = 0;
	while (!t->hit)
	{
		if (t->sdist.x < t->sdist.y)
		{
			t->sdist.x += t->ddist.x;
			t->mp.x += t->stp.x;
			t->side = 0;
		}
		else
		{
			t->sdist.y += t->ddist.y;
			t->mp.y += t->stp.y;
			t->side = 1;
		}
		t->hit = (t->map[t->mp.x][t->mp.y] == '1') ? 1 : t->hit;
	}
	if (!t->side)
		t->perpwdist = (t->mp.x - t->pos.x + (1 - t->stp.x) / 2)
			/ t->raydir.x;
	else
		t->perpwdist = (t->mp.y - t->pos.y + (1 - t->stp.y) / 2)
			/ t->raydir.y;
	t->lnh = (int)(t->winh / t->perpwdist);
}

void	calc_draw_limits(t_c3d *t)
{
	double	pos;

	if (t->side)
		pos = ((double)t->mp.y - t->pos.y + (1. - (double)t->stp.y) / 2.);
	else
		pos = ((double)t->mp.x - t->pos.x + (1. - (double)t->stp.x) / 2.);
	t->shadedist = fabs(pos / (t->side ? t->raydir.y : t->raydir.x));
	t->drws = (-t->lnh / 2) + (t->winh / 2);
	if (t->drws < 0)
		t->drws = 0;
	t->drwe = (t->lnh / 2) + (t->winh / 2);
	if (t->drwe >= t->winh)
		t->drwe = t->winh - 1;
}
