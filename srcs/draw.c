/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:24:11 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/31 01:11:07 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pxl(t_c3d *t, int x, int y)
{
	t->color = shade_color(t->color, t->shadedist);
	ft_memcpy(t->imgptr + 4 * t->winw * y + x * 4, &t->color, sizeof(int));
}

int		get_pxl_color(t_c3d *t, t_int txpos)
{
	return (*(int *)(&t->tx[t->txid].data[txpos.y % TX_H *
		t->tx[t->txid].sizeline + txpos.x % TX_W * t->tx[t->txid].bpp / 8]));
}

void	draw_sky_flr(t_c3d *t, int y)
{
	t_int	cell;
	t_int	txpos;
	int		x;

	x = -1;
	while (++x < t->winw)
	{
		cell = (t_int){(int)t->flr.x, (int)t->flr.y};
		txpos.x = (int)((TX_W * 2) * (t->flr.x - cell.x)) & ((TX_W * 2) - 1);
		txpos.y = (int)((TX_H * 2) * (t->flr.y - cell.y)) & ((TX_H * 2) - 1);
		t->flr = (t_double){t->flr.x + t->flrstp.x, t->flr.y + t->flrstp.y, 0};
		if (x < t->winw && (t->winh - y - 1) < t->winh)
		{
			t->txid = t->tex_cl && t->tex_flr ? 6 : 5;
			t->color = (t->tex_cl) ? get_pxl_color(t, txpos) : t->cl_color;
			draw_pxl(t, x, t->winh - y - 1);
		}
		if (x < t->winw && y < t->winh)
		{
			t->txid = 5;
			t->color = (t->tex_flr) ? get_pxl_color(t, txpos) : t->flr_color;
			draw_pxl(t, x, y);
		}
	}
}

void	draw_wall(t_c3d *t)
{
	if (t->side == 0)
		t->wllx = t->pos.y + t->perpwdist * t->raydir.y;
	else
		t->wllx = t->pos.x + t->perpwdist * t->raydir.x;
	t->txpos.x = (int)(t->wllx * (double)(TX_W));
	if (!(t->raydir.x == 0))
		t->txpos.x = TX_W - t->txpos.x - 1;
	t->txpos.x = abs(t->txpos.x);
	while (t->drws < t->drwe)
	{
		if (t->side)
			t->txid = (t->raydir.y < 0) ? 3 : 2;
		else
			t->txid = (t->raydir.x < 0) ? 0 : 1;
		if (t->x < t->winw && t->drws < t->winh)
		{
			t->txpos.y = abs((((t->drws * 2 - t->winh + t->lnh) * 64)
			/ t->lnh) / 2);
			t->color = get_pxl_color(t, t->txpos);
			draw_pxl(t, t->x, t->drws);
		}
		(t->drws)++;
	}
}

void	draw_sprite(t_c3d *t, t_raysprite *s, int i)
{
	int	d;

	s->x = s->drws.x - 1;
	while (++s->x < s->drwe.x)
	{
		s->txpos.x = (int)(256 * (s->x - (-s->spritew / 2 + s->screenx))
			* TX_W / s->spritew) / 256;
		s->y = s->drws.y - 1;
		if (s->x > 0 && s->x < t->winw && s->transform.y > 0 &&
			s->transform.y < t->bufz[s->x] && (t->shadedist = s->transform.y))
			while (++s->y < s->drwe.y)
			{
				d = s->y * 256 - t->winh * 128 + s->spriteh * 128;
				s->txpos.y = ((d * TX_H) / s->spriteh) / 256;
				t->txid = t->sprites[i]->txid;
				if (t->tx[t->txid].data[s->txpos.y % TX_H
					* t->tx[t->txid].sizeline + s->txpos.x % TX_W
					* t->tx[t->txid].bpp / 8] != 0)
				{
					t->color = get_pxl_color(t, s->txpos);
					draw_pxl(t, s->x, s->y);
				}
			}
	}
}
