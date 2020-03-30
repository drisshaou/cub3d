/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:24:11 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/24 02:29:25 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pxl(t_c3d *t, int x, int y)
{
	t->color = shade_color(t->color, t->shadedist);
	ft_memcpy(t->imgptr + 4 * t->winw * y + x * 4, &t->color, sizeof(int));
}

int		get_pxl_color(t_c3d *t, t_int _tx)
{
	return (*(int *)(&t->tx[t->txid].data[_tx.y % tx_h *
		t->tx[t->txid].sizeline + _tx.x % tx_w * t->tx[t->txid].bpp / 8]));
}

void	draw_sky_flr(t_c3d *t, int y)
{
	t_int	_cell;
	int		x;

	x = -1;
	while (++x < t->winw)
	{
		_cell.x = (int)t->flr.x;
		_cell.y = (int)t->flr.y;
		t->_t.x = (int)((tx_w * 2) * (t->flr.x - _cell.x)) & ((tx_w * 2) - 1);
		t->_t.y = (int)((tx_h * 2) * (t->flr.y - _cell.y)) & ((tx_h * 2) - 1);
		t->flr.x += t->flrstp.x;
		t->flr.y += t->flrstp.y;
		if (x < t->winw && (t->winh - y - 1) < t->winh)
		{
			t->txid = t->tex_cl && t->tex_flr ? 6 : 5;
			t->color = (t->tex_cl) ? get_pxl_color(t, t->_t) : t->cl_color;
			draw_pxl(t, x, t->winh - y - 1);
		}
		if (x < t->winw && y < t->winh)
		{
			t->txid = 5;
			t->color = (t->tex_flr) ? get_pxl_color(t, t->_t) : t->flr_color;
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
	t->_tx.x = (int)(t->wllx * (double)(tx_w));
	if (!(t->raydir.x == 0))
		t->_tx.x = tx_w - t->_tx.x - 1;
	t->_tx.x = abs(t->_tx.x);
	while (t->drws < t->drwe)
	{
		if (t->side)
			t->txid = (t->raydir.y < 0) ? 3 : 2;
		else
			t->txid = (t->raydir.x < 0) ? 0 : 1;
		if (t->x < t->winw && t->drws < t->winh)
		{
			t->_tx.y = abs((((t->drws * 2 - t->winh + t->lnh) * 64)/ t->lnh) / 2);
			t->color = get_pxl_color(t, t->_tx);
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
		s->_tx.x = (int)(256 * (s->x - (-s->spritew / 2 + s->screenx))
			* tx_w / s->spritew) / 256;
		s->y = s->drws.y - 1;
		if (s->x > 0 && s->x < t->winw && s->transform.y > 0 &&
			s->transform.y < t->bufz[s->x] && (t->shadedist = s->transform.y))
			while (++s->y < s->drwe.y)
			{
				d = s->y * 256 - t->winh * 128 + s->spriteh * 128;
				s->_tx.y = ((d * tx_h) / s->spriteh) / 256;
				t->txid = t->sprites[i]->txid;
				if (t->tx[t->txid].data[s->_tx.y % tx_h
					* t->tx[t->txid].sizeline + s->_tx.x % tx_w
					* t->tx[t->txid].bpp / 8] != 0)
				{
					t->color = get_pxl_color(t, s->_tx);
					draw_pxl(t, s->x, s->y);
				}
			}
	}
}
