/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:07:49 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 20:16:45 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_c3d *t)
{
	double	old_xdir;
	double	old_xplane;
	double	_cos;
	double	_sin;
	double	m;

	old_xdir = t->dir.x;
	old_xplane = t->pln.x;
	m = t->rtr ? -1. : 1.;
	_cos = cos(m * t->rts);
	_sin = sin(m * t->rts);
	if (t->rtr || t->rtl)
	{
		t->dir.x = t->dir.x * _cos - t->dir.y * _sin;
		t->dir.y = old_xdir * _sin + t->dir.y * _cos;
		t->pln.x = t->pln.x * _cos - t->pln.y * _sin;
		t->pln.y = old_xplane * _sin + t->pln.y * _cos;
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
	double	_cos;
	double	_sin;
	double	m;

	if (t->mvr || t->mvl)
	{
		m = t->mvl ? (1. + t->mvs) : -(1. + t->mvs);
		_cos = cos(M_PI / 2);
		_sin = sin(M_PI / 2);
		new_xdir = m * (t->dir.x * _cos - t->dir.y * _sin);
		new_ydir = m * (t->dir.x * _sin + t->dir.y * _cos);
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
