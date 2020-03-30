/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 06:35:39 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/23 03:41:58 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_small_map(t_c3d *t)
{
	t_int	c;
	int		l;
	int		cols;
	int		rows;
	int		i;

	cols = 0;
	rows = ft_get_tab_size(t->map);
	l = 5;
	c.x = -1;
	while (++c.x < rows)
		while (cols < (int)ft_strlen(t->map[c.x]))
			cols = (int)ft_strlen(t->map[c.x]);
	c.x = -1;
	while (++c.x < rows && (c.y = -1))
	{
		draw_small_background(t, rows, cols, c, l);
		draw_small_walls(t, rows, cols, c, l);
	}
	i = -1;
	while (++i < t->nbsprites)
	{
		c = (t_int){t->sprites[i]->x, t->sprites[i]->y};
		draw_small_sprites(t, rows, cols, c, l);
	}
	draw_small_position(t, rows, cols, l);
}

void	draw_small_background(t_c3d *t, int rows, int cols, t_int c, int l)
{
	t_int	d;
	int		k;
	int		j;

	while (++c.y < cols && (j = l))
		while (--j >= 0 && (k = l))
			while (--k >= 0)
			{
				d.x = (t->winw - cols * l) + c.y * l + j;
				d.y = (t->winh - rows * l) + c.x * l + k;
				t->color =  *(int *)(t->imgptr + 4 * t->winw * d.y + d.x * 4);
				t->shadedist = 1.3;
				draw_pxl(t, d.x, d.y);
			}
}

void	draw_small_walls(t_c3d *t, int rows, int cols, t_int c, int l)
{
	t_int	d;
	int		k;
	int		j;

	while (++c.y < (int)ft_strlen(t->map[c.x]) && (j = l))
		if (t->map[c.x][c.y] == '1')
			while (--j >= 0 && (k = l))
				while (--k >= 0)
				{
					d.x = (t->winw - cols * l) + c.y * l + j;
					d.y = (t->winh - rows * l) + c.x * l + k;
					t->color =  *(int *)(t->imgptr + 4 * t->winw * d.y
						+ d.x * 4);
					t->shadedist = 5.9;
					draw_pxl(t, d.x, d.y);
				}
}

void	draw_small_position(t_c3d *t, int rows, int cols, int l)
{
	t_int	d;
	int		k;
	int		j;

	j = l;
	while (--j >= 0 && (k = l) && (t->color = rgb_int(0, 255, 0)))
		while (--k >= 0)
		{
			d.x = (t->winw - cols * l) + (int)t->pos.y * l + j;
			d.y = (t->winh - rows * l) + (int)t->pos.x * l + k;
			t->shadedist = 1;
			draw_pxl(t, d.x, d.y);
		}
}

void	draw_small_sprites(t_c3d *t, int rows, int cols, t_int c, int l)
{
	t_int	d;
	int		k;
	int		j;

	j = l;
	while (--j >= 0 && (k = l) && (t->color = rgb_int(255, 168, 0)))
		while (--k >= 0)
		{
			d.x = (t->winw - cols * l) + c.y * l + j;
			d.y = (t->winh - rows * l) + c.x * l + k;
			t->shadedist = 1;
			draw_pxl(t, d.x, d.y);
		}
}
