/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:02:08 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/19 03:32:27 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_sprite(t_c3d *t)
{
	t_raysprite	s;
	int			i;

	i = -1;
	while (++i < t->nbsprites)
	{
		init_cast_sprite(t, &s, i);
		calc_sprite_w_h(t, &s);
		draw_sprite(t, &s, i);
	}
}

void	init_cast_sprite(t_c3d *t, t_raysprite *s, int i)
{
	s->sprite.x = t->sprites[i]->x - t->pos.x;
	s->sprite.y = t->sprites[i]->y - t->pos.y;
	s->invdet = 1.0 / (t->pln.x * t->dir.y - t->dir.x * t->pln.y);
	s->transform.x = s->invdet
		* (t->dir.y * s->sprite.x - t->dir.x * s->sprite.y);
	s->transform.y = s->invdet
		* (-t->pln.y * s->sprite.x + t->pln.x * s->sprite.y);
}

void	calc_sprite_w_h(t_c3d *t, t_raysprite *s)
{
	s->screenx = (int)((t->winw / 2) * (1 + s->transform.x / s->transform.y));
	s->spriteh = abs((int)(t->winh / s->transform.y));
	s->drws.y = -s->spriteh / 2 + t->winh / 2;
	if (s->drws.y < 0)
		s->drws.y = 0;
	s->drwe.y = s->spriteh / 2 + t->winh / 2;
	if (s->drwe.y >= t->winh)
		s->drwe.y = t->winh - 1;
	s->spritew = abs((int)(t->winh / s->transform.y));
	s->drws.x = -s->spritew / 2 + s->screenx;
	if (s->drws.x < 0)
		s->drws.x = 0;
	s->drwe.x = s->spritew / 2 + s->screenx;
	if (s->drwe.x >= t->winw)
		s->drwe.x = t->winw - 1;
}
