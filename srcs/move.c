/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:07:49 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/30 16:35:28 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_c3d *t)
{
	double	old_xdir;
	double	old_xplane;
	double	cosi;
	double	sinu;
	double	m;

	old_xdir = t->dir.x;
	old_xplane = t->pln.x;
	m = t->rtr ? -1. : 1.;
	cosi = cos(m * t->rts);
	sinu = sin(m * t->rts);
	if (t->rtr || t->rtl)
	{
		t->dir.x = t->dir.x * cosi - t->dir.y * sinu;
		t->dir.y = old_xdir * sinu + t->dir.y * cosi;
		t->pln.x = t->pln.x * cosi - t->pln.y * sinu;
		t->pln.y = old_xplane * sinu + t->pln.y * cosi;
	}
}

void	move_vertical(t_c3d *t)
{
	double	xdir;
	double	ydir;
	double	m;

	if (t->mvu || t->mvd)
	{
		m = t->mvu ? (1. + t->mvs) : -(1. + t->mvs);
		xdir = m * t->dir.x;
		ydir = m * t->dir.y;
		if (t->map[(int)(t->pos.x + xdir * t->mvs)][(int)t->pos.y] == '0')
			t->pos.x += xdir * t->mvs;
		if (t->map[(int)t->pos.x][(int)(t->pos.y + ydir * t->mvs)] == '0')
			t->pos.y += ydir * t->mvs;
	}
}

void	move_horizontal(t_c3d *t)
{
	double	new_xdir;
	double	new_ydir;
	double	cosi;
	double	sinu;
	double	m;

	if (t->mvr || t->mvl)
	{
		m = t->mvl ? (1. + t->mvs) : -(1. + t->mvs);
		cosi = cos(M_PI / 2);
		sinu = sin(M_PI / 2);
		new_xdir = m * (t->dir.x * cosi - t->dir.y * sinu);
		new_ydir = m * (t->dir.x * sinu + t->dir.y * cosi);
		if (t->map[(int)(t->pos.x + new_xdir * t->mvs)][(int)t->pos.y] == '0')
			t->pos.x += new_xdir * t->mvs;
		if (t->map[(int)t->pos.x][(int)(t->pos.y + new_ydir * t->mvs)] == '0')
			t->pos.y += new_ydir * t->mvs;
	}
}

int		move(t_c3d *t)
{
	move_vertical(t);
	move_horizontal(t);
	rotate(t);
	raycast(t);
	if (t->save)
	{
		t->save = 0;
		create_bmp(t);
		ft_exit(t);
	}
	return (0);
}
