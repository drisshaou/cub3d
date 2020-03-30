/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:35:15 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 19:46:58 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_c3d *t)
{
	t->img = mlx_new_image(t->mlx, t->winw, t->winh);
	t->imgptr = mlx_get_data_addr(t->img, &(t->bpp), &(t->sl), &(t->endian));
	cast_sky_flr(t);
	cast_walls(t);
	cast_sprite(t);
	draw_small_map(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}
